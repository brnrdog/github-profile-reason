let mapEdges = edges =>
  Belt.Option.getWithDefault(edges, [||])
  |> Array.map(edge => Belt.Option.getExn(edge)##node);