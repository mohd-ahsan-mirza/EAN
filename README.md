# EAN

Most bookstores use the International Article Number (EAN) system to identify the books that they sell.  EAN stood for European Article Number before being adopted internationally.  A book's EAN is the number alongside the barcode typically found on its back cover.  Publishers assign unique EANs to each edition that they publish.  An EAN, once assigned, can never be re-used by anyone.  You can find more information on this numbering system at isbn-international.org and on Wikipedia.  The GS1 organization oversees the EAN identification system.

A bookstore, when it places an order with a publisher, identifies the publication being ordered by its EAN.  The publisher prints the EAN on the cover of each copy printed.  The universal use of EANs minimizes errors due to typographical mistakes or confusions amongst similar titles. 

Structure of an EAN

The EAN system uses a barcode with thirteen characters.  The first three characters identify the application.  In the case of books these are either 978 or 979.  An EAN starting with either set of digits is called a Bookland EAN.

A Valid EAN

All of the characters in an EAN are digits between 0 and 9 inclusive.  The rightmost digit is called the check digit. 

 9780003194876
The check digit is determined as follows.  Every second digit from the second to the twelveth - counting from left to right - is multiplied by 3.  The sum of these products and the remaining digits, including the check digit, must be divisible without remainder by 10.  If there is a remainder, the number is not a valid EAN.  (Other systems that use a check digit include Social Insurance Numbers, Universal Product Codes and credit cards.)

A Registered EAN

A valid EAN may or may not be registered under GS1 organization.  A registered EAN that meets GS1 standards consists of five elements:

a prefix element
a registration group or area element
a registrant or publisher element
a publication or title element
a check digit
The prefix element identifies the application area.  The GS1 Organization assigns this element.  This element consists of three (3) digits.  For example, the following are valid Bookland EANs

 978 0003194876
 978 9070002046
 978 9972000003
The group or area identifier identifies the country, region or language area participating in the EAN system.  This element consists of between one (1) and five (5) digits inclusive.  For example,

 978 0 003194876
 978 90 70002046
 978 9972 000003
The area element 0 stands for the English speaking region of the world: Australia, English Canada, Gibraltar, Ireland, (Namibia), New Zealand, Puerto Rico, South Africa, Swaziland, United Kingdom, the United States of America and Zimbabwe. 

The publisher element is the third element from the left.  GS1 publishes ranges of publisher identifiers for each area.  Each national GS1 branch assigns publisher identifiers within the range for its own area and maintains an up-to-date register of publishers and their identifiers.  This element consists of between one (1) and seven (7) digits.  For example,

 978 0 00 3194876
 978 90 70002 046
 978 9972 00 0003
The title element is the fourth element from the left and identifies the publication itself.  Publishers themselves assign a unique title identifier to each specific edition of a publication.  This component consists of between one (1) and six (6) digits.  For example,

 978 0 00 319487 6
 978 90 70002 04 6
 978 9972 00 000 3
Determining the different elements of a Bookland EAN is complicated because the number of digits in each element varies.  However, the total number of digits in the first four elements is always twelve (12). 

Finding the Elements of an EAN

Finding the elements of an EAN is an iterative process.  We start with a valid EAN supplied by a client.  We test the leftmost digits until we find an area element that is listed in the prefix table.  Once we have found the area element, we check the ranges of publisher identifiers in the same prefix table.  The upper limit of a range has the same number of digits as its lower limit.  For example, the ranges for the English speaking area of the world (area 0) are:

 00 19
 200 699
 7000 8499
 85000 89999
 900000 949999
 9500000 9999999
Note that, for this particular area, the first publisher range starts with a two digit value.  Publisher identifiers such as 00, 01, 03, 10, 19 are within this range, while identifiers such as 0, 1, 2, 3, 9 are NOT within this range.  The minimum number of digits in the publisher identifiers of any range can vary from area to area. 

You can find the GS1 prefix table in the repository.  Each record in this table describes one publisher range.  The record consists of three fields: an area element, the lowest value for the publisher range and the highest value for the publisher range.  You have permission to use this table for educational purposes only.  You must obtain written permission directly from GS1 for any other use.
