module Styles = {
  open Css;
  open Theme;

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
        Breakpoints.medium,
        [
          margin(em(1.0)),
          flexWrap(`nowrap),
          marginRight(px(0)),
          firstChild([marginLeft(px(0))]),
          lastChild([marginLeft(px(0)), marginRight(px(0))]),
        ],
      ),
      media(
        Breakpoints.large,
        [
          marginRight(em(1.0)),
          lastChild([marginLeft(em(1.0)), marginRight(px(0))]),
        ],
      ),
    ]);
};