module Styles = {
  open Css;

  let heading = style([fontSize(em(1.25)), marginBottom(em(1.0))]);

  let list =
    style([
      display(`flex),
      justifyContent(`spaceBetween),
      flexWrap(`wrap),
    ]);

  let card =
    style([
      width(`percent(100.0)),
      flex(1),
      marginBottom(em(1.0)),
      media(
        "(min-width: 768px)",
        [
          margin(em(1.0)),
          flexWrap(`nowrap),
          marginRight(px(0)),
          firstChild([marginLeft(px(0))]),
          lastChild([marginLeft(px(0)), marginRight(px(0))]),
        ],
      ),
      media(
        "(min-width: 1024px)",
        [
          marginRight(em(1.0)),
          lastChild([marginLeft(em(1.0)), marginRight(px(0))]),
        ],
      ),
    ]);
};