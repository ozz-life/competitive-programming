/**
 * @param {string} command
 * @return {string}
 */

var interpret = function (command) {
    return command.replaceAll("()", "o").replaceAll("(al)", "al");
};

////////////////////////////////////////////////////////////////////////////////
var interpret = function (command) {
    const interpret = command => command.split("()").join("o").split("(al)").join("al")
};
