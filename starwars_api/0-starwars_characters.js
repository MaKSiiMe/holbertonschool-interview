#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(filmUrl, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  const film = JSON.parse(body);
  const characters = film.characters;

  printCharacters(characters, 0);
});

/**
 * printCharacters - Prints character names in order
 * @param {Array} characters - Array of character URLs
 * @param {Number} index - Current index
 */
function printCharacters (characters, index) {
  if (index >= characters.length) {
    return;
  }

  request(characters[index], (error, response, body) => {
    if (error) {
      console.error(error);
      return;
    }

    const character = JSON.parse(body);
    console.log(character.name);
    printCharacters(characters, index + 1);
  });
}
