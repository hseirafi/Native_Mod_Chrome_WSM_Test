let rainfall = require('bindings')('rainfall')
let location = {
    latitude : 40.71, longitude : -74.01,
       samples : [
          { date : "2015-06-07", rainfall : 2.1 },
          { date : "2015-06-14", rainfall : 0.5}, 
          { date : "2015-06-21", rainfall : 1.5}, 
          { date : "2015-06-28", rainfall : 1.3}, 
          { date : "2015-07-05", rainfall : 0.9}
       ] };

let avg = rainfall.avg_rainfall(location)
console.log("Average rain fall = " + avg + "cm");

let data = rainfall.data_rainfall(location);

console.log("Mean = " + data.mean)
console.log("Median = " + data.median);
console.log("Standard Deviation = " + data.standard_deviation);
console.log("N = " + data.n);

const makeup = function(max) {
    return Math.round(max * Math.random() * 100)/100;
}

// Build some dummy locations
var locations = []
for (let i = 0; i < 10; i++ ) {
    const loc = {
        latitude: makeup(180), 
        longitude: makeup(180), 
        samples : [
            {date: "2015-07-20", rainfall: makeup(3)}, 
            {date: "2015-07-21", rainfall: makeup(3)}, 
            {date: "2015-07-22", rainfall: makeup(3)}, 
            {date: "2015-07-23", rainfall: makeup(3)}
        ]
    }
    locations.push(loc);
}

// Invoke the Addon
const results = rainfall.calculate_results(locations);

// Report the results from C++
let i = 0;
results.forEach(function(result){
    console.log("Result for Location " + i);
    console.log("--------------------------");
    console.log("\tLatitude:         " + locations[i].latitude.toFixed(2));
    console.log("\tLongitude:        " + locations[i].longitude.toFixed(2));
    console.log("\tMean Rainfall:    " + result.mean.toFixed(2) + "cm");
    console.log("\tMedian Rainfall:  " + result.median.toFixed(2) + "cm");
    console.log("\tStandard Dev.:    " + result.standard_deviation.toFixed(2) + "cm");
    console.log("\tNumber Samples:   " + result.n);
    console.log();
    i++;
})