#!/usr/bin/node

// Using request to implement a http request to the
// starWars API

const request = require('request');

const id = process.argv.splice(2);

const URL = `https://swapi-api.hbtn.io/api/films/${id}/`;

request(URL, (error, response, body) => {
  if (response.statusCode !== 200) console.log(error);
  else {
    const data = JSON.parse(body);
    const characters = data.characters;

    const charactersList = (urlId) => {
      const createPromise = new Promise((resolve, reject) => {
        request(urlId, (error, response, body) => {
          if (error) reject(error);
          resolve(JSON.parse(body));
        });
      });
      return createPromise;
    };

    characters.map(async (url) => {
      const character = await charactersList(url);
      console.log(character.name);
    });
  }
});
