#----------------------------------------------------------------------------
#       Make Workspace
#
# $Id: MakeWorkspaceCreator.pm 2035 2011-10-06 15:05:21Z johnnyw $
#
# This file was generated by MPC.  Any changes made directly to
# this file will be lost the next time it is generated.
#
# MPC Command:
# /home/hilljh/MPC/mwc.pl -type make /home/hilljh/cs363-sandbox/assignment4/prajarub/cs363-fall2021-assignment4
#
#----------------------------------------------------------------------------


all: assignment4

clean depend generated realclean check-syntax $(CUSTOM_TARGETS):
	@$(MAKE) -f Makefile.assignment4 $(@)

.PHONY: assignment4
assignment4:
	@$(MAKE) -f Makefile.assignment4 all

project_name_list:
	@echo assignment4
