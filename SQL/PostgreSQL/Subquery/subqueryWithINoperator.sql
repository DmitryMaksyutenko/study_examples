SELECT
  film_id,
  title
FROM
  film
WHERE
film_id IN (
  SELECT
    inventory.film_id
  FROM
    rental
  INNER JOIN inventory ON
    inventory.inventory_id = rental.inventory_id
);

-- Shows language from the language table for the film, film identification number, and title from film table.
SELECT
  name,
  film_id,
  title
FROM
  language, film
WHERE
  name IN (
            SELECT
              anguage.name
            FROM
              language
            WHERE
              language.language_id = film.language_id
          )
ORDER BY
  film_id;
