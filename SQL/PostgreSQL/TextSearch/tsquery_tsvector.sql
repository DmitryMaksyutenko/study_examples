/*
    A document is the unit of searching in a full text search system.

    For text search purposes, each document must be reduced to the preprocessed 'tsvector' format.
    Searching and ranking are performed entirely on the tsvector representation
    of a document — the original text need only be retrieved when the document has been selected
    for display to a user.
    The elements of a 'tsvector' are lexemes, which are assumed already normalized.

    A 'tsquery' contains search terms, which must be already-normalized lexemes,
    and may combine multiple terms using AND (&), OR (|), NOT (!), and FOLLOWED BY(<->) operators.

    There are functions to_tsquery(), plainto_tsquery(), and phraseto_tsquery()
    that are helpful in converting user-written text into a proper tsquery,
    primarily by normalizing words appearing in the text.
    Similarly, to_tsvector() is used to parse and normalize a document string

    @@ - the match operator. Returrn true if tsvector(document) mathces the tsquery(query).

*/

SELECT 'a fat cat sat on a mat and ate a fat rat'::tsvector @@ 'cat & rat'::tsquery;

SELECT to_tsvector('This is some text for searching.') @@ to_tsquery('search');

SELECT to_tsvector('Fatal error!') @@ to_tsquery('fatal');
SELECT to_tsvector('Fatal error!') @@ to_tsquery('!fatal');

SELECT to_tsvector('Error is not fatal!') @@ to_tsquery('fatal & is');

SELECT to_tsvector('Error is not fatal!') @@ to_tsquery('Error & !fatal');

SELECT to_tsvector('Error is not!') @@ to_tsquery('Error | !fatal');

SELECT to_tsvector('Fatal error!') @@ to_tsquery('fatal <-> error');
SELECT to_tsvector('Fatal big error!') @@ to_tsquery('fatal <-> error');
