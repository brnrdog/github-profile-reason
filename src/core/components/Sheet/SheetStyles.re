module Styles = {
  open Css;

  let sheet =
    style([
      background(hex("fff")),
      borderRadius(em(0.25)),
      padding(em(1.0)),
      boxShadow(hex("eee")),
    ]);
};