let formatNumeral: int => string = [%raw
  {|
  number => {
    var numeral = require('numeral');
    return numeral(number).format("0,0");
  }
|}
];