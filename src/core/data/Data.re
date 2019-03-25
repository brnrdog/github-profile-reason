/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

/* Create an HTTP Link */
let httpLink =
  ApolloLinks.createHttpLink(
    ~uri="https://api.github.com/graphql",
    ~headers=
      Js.Json.parseExn(
        "{\"Authorization\": \"Bearer 627e09e4f04efaf3f9f8b4604319e051b6368828\" }",
      ),
    (),
  );

let instance =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());