include $(TESTSROOTDIR)/testcase.mk
include $(TESTSROOTDIR)/../main.mk
export TEST_TIMEOUT=3m
CFLAGS+=-I$(TESTSROOTDIR)/../bbinc -D_GNU_SOURCE

CDB2LIBS=$(SYSPATH) -L$(SRCHOME)/cdb2api -l:libcdb2api.a -L$(SRCHOME)/protobuf/ -lcdb2protobuf -lprotobuf-c -lsqlite3 -lpthread -lssl -lcrypto

tool: comdb2_sqltest

comdb2_sqltest: sqllogictest.o md5.o slt_comdb2.o slt_sqlite.o endian_core.o client_datetime.o
	echo $(CC) -o $@ $?
	$(CC) -o $@ $? $(CDB2LIBS)
	
%.o: %.c
	echo $(CC) -o $@ -c $< $(CFLAGS) -I$(TESTSROOTDIR)/../cdb2api
	$(CC) -o $@ -c $< $(CFLAGS) -I$(TESTSROOTDIR)/../cdb2api
