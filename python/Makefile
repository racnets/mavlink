MODULE = mavlink
PROGS = test_mavlink2python
MODULE_FILES = _$(MODULE).so $(MODULE).py $(MODULE).pyc $(MODULE)_wrap.c

all: swig setup $(PROGS)

SWIG = /usr/bin/swig2.0
SWIGFLAGS = -python
SWIGFLAGS = -I/usr/include -I/usr/include/linux -I../include -I../include/huch -includeall -python

swig:
	$(SWIG) $(SWIGFLAGS) $(MODULE).i

setup:
	python setup.py build_ext --inplace

clean:
	python setup.py clean
	$(RM) *~ $(PROGS) $(MODULE_FILES)
