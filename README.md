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
* C / C++ (also using C frameworks)
    * jsoncpp
    * Google Protobuf
    * protobuf-c
* Python (also Cython?)
    * stdlib JSON
    * Google Protobuf
    * ujson
* Go
    * stdlib JSON
    * Google Protobuf
    * YGOT Marshal
* Rust
    * quick-protobuf
    * rust-protobuf
    * stdlib json

Operations:
* Serialize
* Deserialize

Data:
* Small messages (~1kB)
* Big messages (~10 MB)
