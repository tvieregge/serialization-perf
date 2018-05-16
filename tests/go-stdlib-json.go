package main

import (
    "fmt"
    "encoding/json"
    "os"
    "io/ioutil"
    "time"
)


func main() {
    if len(os.Args) != 3 {
        fmt.Println("Command format: go-stdlib-json [small-json] [large-json]")
    }

    small := os.Args[1]
    big := os.Args[2]

    // Test loading
    big_duration, total_big_duration := load_json(big, 96)
    small_duration, total_small_duration := load_json(small, 648494)
    fmt.Printf("go-stdlib-json-deserialize,%v,%v,%v,%v\n", small_duration,
               total_small_duration, big_duration, total_big_duration)

    // Test serializing
    big_duration, total_big_duration = dump_json(big, 67)
    small_duration, total_small_duration = dump_json(small, 786217)
    fmt.Printf("go-stdlib-json-serialize,%v,%v,%v,%v\n", small_duration,
               total_small_duration, big_duration, total_big_duration)
}


func load_json(jFile string, iterations int) (float64, float64) {
    jsonBytes, err := ioutil.ReadFile(jFile)
    if err != nil {
        fmt.Println("Error! Could not open file ", jFile)
        return -1.0, -1.0
    }
    // Output data
    var data map[string]interface{}

    start := time.Now()
    for i := 0; i < iterations; i++ {
        json.Unmarshal(jsonBytes, &data)
    }
    end := time.Now()

    // Amount of time it took to load the JSON file
    diff := end.Sub(start)
    return 1e-9*float64(diff.Nanoseconds())/float64(iterations), 1e-9*float64(diff.Nanoseconds())
}


func dump_json(jFile string, iterations int) (float64, float64) {
    jsonBytes, err := ioutil.ReadFile(jFile)
    if err != nil {
        fmt.Println("Error! Colud not open file ", jFile)
        return -1.0, -1.0
    }

    var testData map[string]interface{}
    json.Unmarshal(jsonBytes, &testData)

    start := time.Now()
    for i := 0; i < iterations; i++ {
        _, err = json.Marshal(testData)
    }
    end := time.Now()

    diff := end.Sub(start)
    return 1e-9*float64(diff.Nanoseconds())/float64(iterations), 1e-9*float64(diff.Nanoseconds())
}
