# 0x0F. Star Wars API

- By: Alexa Orrico, Software Engineer at Holberton School
- Weight: 1
- Project will start Aug 8, 2022 12:00 AM, must end by Aug 12, 2022 12:00 AM
- was released at Aug 10, 2022 12:00 AM
- An auto review will be launched at the deadline

## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be interpreted on Ubuntu 14.04 LTS using `node` (version 10.14.x)
- All your files should end with a new line
- The first line of all your files should be exactly `#!/usr/bin/node`
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should be `semistandard` compliant. [Rules of Standard](https://intranet.hbtn.io/rltoken/7fwr0AM1Ph_2YpibFmY3wA 'Rules of Standard') + [semicolons on top](https://intranet.hbtn.io/rltoken/s5n5IBBMZqfuk62xeimYrg 'semicolons on top'). Also as reference: [AirBnB style](https://intranet.hbtn.io/rltoken/nTwC1UjurAXd9SajmXhb2w 'AirBnB style')
- All your files must be executable
- The length of your files will be tested using `wc`
- You are not allowed to use `var`

## More Info

### Install Node 10

```
$ curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash -
$ sudo apt-get install -y nodejs

```

### Install semi-standard

[Documentation](https://intranet.hbtn.io/rltoken/s5n5IBBMZqfuk62xeimYrg 'Documentation')

```
$ sudo npm install semistandard --global

```

### Install `request` module and use it

[Documentation](https://intranet.hbtn.io/rltoken/-XDycLgGLJXzwsj9cZGFUw 'Documentation')

```
$ sudo npm install request --global
$ export NODE_PATH=/usr/lib/node_modules

```

## Tasks

### 0. Star Wars Characters

Write a script that prints all characters of a Star Wars movie:

- The first positional argument passed is the Movie ID - example: `3` = “Return of the Jedi”
- Display one character name per line **in the same order as the “characters” list in the `/films/` endpoint**
- You must use the [Star wars API](https://intranet.hbtn.io/rltoken/aiMsg1QkH-FuPn7gyo9O6A 'Star wars API')
- You must use the `request` module

```
alexa@ubuntu:~/0x0F$ ./0-starwars_characters.js 3
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Obi-Wan Kenobi
Chewbacca
Han Solo
Jabba Desilijic Tiure
Wedge Antilles
Yoda
Palpatine
Boba Fett
Lando Calrissian
Ackbar
Mon Mothma
Arvel Crynyd
Wicket Systri Warrick
Nien Nunb
Bib Fortuna
alexa@ubuntu:~/0x0F$

```

**Repo:**

- GitHub repository: `holbertonschool-interview`
- Directory: `0x0F-starwars_api`
- File: `0-starwars_characters.js`

Copyright © 2022 Holberton Inc, All rights reserved.
