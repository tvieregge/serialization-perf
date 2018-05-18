COMMON_CFLAGS = -Wall -03

.PHONY: all clean

all : results.csv

clean:
	${RM} results.csv
	${RM} tests/go-stdlib-json
	${RM} tests/*.pb-c.*

results.csv : tests/go-stdlib-json tests/c-protobuf
	./run_tests
	@echo "Done making tests"

#tests/c-protobuf : c-protobuf.o generated-protobuf
	gcc tests/protobuf-c.c tests/test.pb-c.h tests/test.pb-c.c `pkg-config --libs libprotobuf-c`

generated-protobuf : tests/test.proto
	protoc --proto_path=tests --c_out=./tests tests/test.proto

tests/go-stdlib-json :
	go build -o tests/go-stdlib-json tests/go-stdlib-json.go
