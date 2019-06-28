{
  "targets": [
    {
      "target_name": "heavyProcessing",
      "sources": [ "heavyProcessing.cpp", "rotateProcess.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}