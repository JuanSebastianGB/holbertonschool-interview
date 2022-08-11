#!/usr/bin/node

// Using request to implement a http request to the
// starWars API

const request = require('request');

const id = process.argv.splice(2);

const URL = `https://swapi-api.hbtn.io/api/films/${id}`;

request(URL, async (error, response, body) => {
  if (response.statusCode !== 200) console.log(error);
  else {
    const { characters } = JSON.parse(body);

    const charactersList = (urlId) => {
      const createPromise = new Promise((resolve, reject) => {
        request(urlId, (error, response, body) => {
          if (error) reject(error);
          resolve(JSON.parse(body));
        });
      });
      return createPromise;
    };

    for (let i = 0; i < characters.length; i++) {
      const result = await charactersList(characters[i]);
      console.log(result.name);
    }
  }
});
