#!/usr/bin/node

const request = require('request');
const movieId = process.argv.slice(2);
const url = 'https://swapi-api.hbtn.io/api/films/' + movieId;

request(url, async (error, resp, body) => {
  if (error) throw error;
  try {
    const json = JSON.parse(body);

    for (const urlPeople of json.characters) {
      const people = await new Promise((resolve, reject) => {
        request(urlPeople, (err, r, bod) => {
          if (err) throw err;
          resolve(JSON.parse(bod).name);
        });
      });
      console.log(people);
    }
  } catch (error) {
    console.error(error);
  }
});
