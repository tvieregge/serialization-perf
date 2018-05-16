#! /bin/zsh

# Using the Go imports since the proto files are all there
GITHUB_DIR=$HOME/go/src

mkdir -p cpp

for f in `find -name '*.proto'`; do
    protoc -I.:$GITHUB_DIR --cpp_out=cpp $f
done
