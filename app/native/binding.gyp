{
  "targets": [
    {
      "target_name": "rainfall",
      "sources": [ "rainfall.cc" , "rainfall_node.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}