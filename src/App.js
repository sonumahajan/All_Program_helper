import { useEffect, useState } from 'react';
import './App.css';
import Recipe from "./Recipe";

function App() {

  const APP_ID = "728b05dc";
  const APP_KEY = "e172ea81a850b1e06c2db964f443ca5d";
  // const exampleURL = `https://api.edamam.com/search?q=momos&app_id=${APP_ID}&app_key=${APP_KEY}`;

  const [recipes, setRecipes] = useState([]);
  const [search, setSearch] = useState("");
  const [query, setQuery] = useState("kulfi");

  useEffect(() => {
    getRecipes();
  }, [query]); //We kept it an empty arrray so that we get only one time page refresh but after we get a query we can again calll this function. So we added the query inside the array.

  const getRecipes = async () => {
    const response = await fetch(`https://api.edamam.com/search?q=${query}&app_id=${APP_ID}&app_key=${APP_KEY}`);
    const data = await response.json();
    setRecipes(data.hits);
    console.log(data.hits);
  }

  const updateSearch = (e) => {
    setSearch(e.target.value);
  }

  const getSearch = (e) => {
    e.preventDefault(); //To stop the page from refreshing.
    setQuery(search);
    setSearch("");
  }

  return (
    <div className="App">
      <form className="search-form" onSubmit={getSearch}>
        <input className="search-bar" type="text" value={search} placeholder="Search for your favorite recipe!" onChange={updateSearch} />
        <button className="search-button" type="submit">Search</button>
      </form>
      <div className="recipes">
        {
          recipes.map(recipe => (
            <Recipe
              key={recipe.recipe.label}
              title={recipe.recipe.label}
              calories={recipe.recipe.calories}
              image={recipe.recipe.image}
              ingredients={recipe.recipe.ingredients}
              cuisineType={recipe.recipe.cuisineType}
              healthLabels={recipe.recipe.healthLabels}
            />
          ))
        }
      </div>
    </div>
  );
}

export default App;
