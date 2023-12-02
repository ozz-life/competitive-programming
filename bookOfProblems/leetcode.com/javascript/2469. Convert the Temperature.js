celsius = 122.11

/**
 * @param {number} celsius
 * @return {number[]}
 */
 var convertTemperature = function(celsius) {
    let ans = [] // [kelvin, fahrenheit]

    function celsiusToKelvin(celsius) {
        return celsius + 273.15
    }

    function celsiusToFahrenheit(celsius) {
        return celsius * 1.80 + 32
    }
    
    // ans.push(celsiusToKelvin(celsius))
    // ans.push(celsiusToFahrenheit(celsius))
    
    return [celsiusToKelvin(celsius), celsiusToFahrenheit(celsius)]
};

console.log(convertTemperature(celsius));