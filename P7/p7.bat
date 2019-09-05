p7.exe /student /add jacob1 jacob W Betram 3300Oglethorpe Atlanta GA 35423
p7.exe /course /add 11233 fa2018 EE 765 Intro 6 Dr.Norman
p7.exe /enrollment /add 12345 norman1 A
p7.exe /enrollment /display 12345 elirose
p7.exe /student /remove jacob1
p7.exe /course /remove 12345
p7.exe /enrollment /remove 12345 elirose

p7.exe /student /display blazer_id
p7.exe /course /display crn
p7.exe /enrollment /display blazer_id
p7.exe /student /export blazer_id
p7.exe /course /export department
p7.exe /course /export instrutor
p7.exe /enrollment /export crn