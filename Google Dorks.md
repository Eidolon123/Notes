-----------------------------------------------
# Google Dorks
Tags:  #Uni #Recon
Creation date: 2021-10-04

-----------------------------------------------

Google dorks is a method of using [[Google]] to find information not usually visible in the search engine.

## Search Terms

| Term     | Example          | Description                                                       |
| -------- | ---------------- | ----------------------------------------------------------------- |
| site:    | site:example.com | Only returns results from site specified                          |
| inurl:   | inurl:blog       | Returns results where the specified text features in the URL      |
| intext:  | intext:login     | Searches for occurrences of specified word                        |
| intitle: | intitle:Home     | Returns results where specified word features in title of webpage |
| -        | -\<keyword>      | Returns results that do not feature specified word                |
| +        | +\<keyword>      | Will order results by no. of occurrences of specified word        |
|          |                  |                                                                   |


## Useful searches

### Find [[Subdomains]]

`site:google.com -www.google.com`
