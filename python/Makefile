MODULE = mavlink
PROGS = test_mavlink2python
MODULE_FILES = _$(MODULE).so $(MODULE).py $(MODULE).pyc $(MODULE)_wrap.c

all: swig setup $(PROGS)

SWIG = /usr/bin/swig2.0

swig:
	$(SWIG) -python $(MODULE).i

setup:
	python setup.py build_ext --inplace

clean:
	python setup.py clean
	$(RM) *~ $(PROGS) $(MODULE_FILES)