# Performance Analysis for Serialization Frameworks
We're testing Protobuf and JSON.

Schemas are provided by OpenConfig.

Benchmarking across languages, so see if acceptable performance
is possible in each scenario.

## Tests
Want to cover formats:
* JSON
* Protobuf
* XML (low-priority)

Languages:
* C
* C++ (also using C frameworks)
* Python (also Cython?)
* Go
* Rust

Operations:
* Serialize
* Deserialize

Data:
* Small messages (~1kB)
* Big messages (~10 MB)
