ROOT       = .
SWIG_DIR   = ./swig
SRCS       = reference.cxx
INTERFACE  = example.i
INCLUDE    = example.h
TARGET     = main
INT_GO_SIZE  = 64


IS_CPP = -c++

swig-build: 
	swig $(IS_CPP) -go -cgo -intgosize $(INT_GO_SIZE) $(SWIG_DIR)/$(INTERFACE)

build:
	go build -a -v $(ROOT)

swig-clean:
	rm -f $(SWIG_DIR)/$(WRAPC_C) $(SWIG_DIR)/$(WRAPC_C_GO) 