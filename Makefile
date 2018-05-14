.PHONY: all clean

all : results.csv

clean:
	${RM} results.csv
	${RM} tests/go-stdlib-json

results.csv : tests/go-stdlib-json
	./run_tests
	@echo "Done making tests"

tests/go-stdlib-json :
	go build -o tests/go-stdlib-json tests/go-stdlib-json.go
