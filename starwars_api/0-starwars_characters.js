#!/usr/bin/node
const { argv } = require('node:process');
const request = require('request');

const STAR_WARS_API_BASE_URL = 'https://swapi-api.hbtn.io/api/';

async function main () {
  // Check arguments count.
  if (argv.length !== 3) {
    console.error('Usage: ./0-starwars_characters.js <MOVIE_ID>');
    process.exit(1);
  }

  const movieID = Number(argv[2]);

  // Check movie ID type.
  if (!Number.isInteger(movieID) || movieID <= 0) {
    console.error('Movie ID must be a positive integer.');
    process.exit(1);
  }

  // Fetch the movie.
  const movieURL = `${STAR_WARS_API_BASE_URL}films/${movieID.toString()}`;
  const movie = await fetchAPI(movieURL);

  if (!movie) {
    console.log('Movie not found.');
    return;
  }

  // Fetch each character of the movie.
  const people = await Promise.all(
    movie.characters.map(characterURL => fetchAPI(characterURL))
  );

  // Log the results.
  people.forEach((person) => {
    if (person) {
      console.log(person.name);
    } else {
      console.log('Character not found.');
    }
  });
}

function fetchAPI (url) {
  // Fetch Star Wars API.
  return new Promise((resolve, reject) => {
    request.get(url, (err, response, body) => {
      if (err) {
        reject(err);
        return;
      }

      if (response.statusCode === 404) {
        resolve(null);
        return;
      }

      resolve(JSON.parse(body));
    });
  });
}

main();
