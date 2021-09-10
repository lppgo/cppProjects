ROOT       = .
SWIG_DIR    = ./swig
SRCS       = example.c
INTERFACE  = example.i
TARGET     = main
INT_GO_SIZE  = 64

WRAPC_C = example_wrap.c
WRAP_C_GO = example.go

swig-build: 
	swig -go -cgo -intgosize $(INT_GO_SIZE) -package $(SWIG_DIR) $(SWIG_DIR)/$(INTERFACE)

build:
	go build  $(ROOT)

swig-clean:
	rm -f $(SWIG_DIR)/$(WRAPC_C) $(SWIG_DIR)/$(WRAPC_C_GO) 