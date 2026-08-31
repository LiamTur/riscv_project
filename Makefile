TOP ?= nand_gate

RTL_DIR := rtl
TB_DIR  := tb
OBJDIR  := obj_dir/$(TOP)

SRC := $(RTL_DIR)/$(TOP).sv
PKG := $(RTL_DIR)/$(TOP)_pkg.sv
TB  := $(TB_DIR)/tb_$(TOP).cpp

.PHONY: all run clean list

all: $(OBJDIR)/V$(TOP)

$(OBJDIR)/V$(TOP): $(SRC) $(TB)
	verilator -Wall --cc $(PKG) $(SRC) --top-module $(TOP) --exe $(TB) --Mdir $(OBJDIR)
	$(MAKE) -j -C $(OBJDIR) -f V$(TOP).mk V$(TOP)

run: all
	./$(OBJDIR)/V$(TOP)

clean:
	rm -rf obj_dir/*

cpp: 
	verilator -Wall --cc $(PKG) $(SRC) --top-module $(TOP) --exe $(TB) --Mdir $(OBJDIR)

list:
	@ls $(RTL_DIR)/*.sv | xargs -n1 basename | sed 's/\.sv$$//'
