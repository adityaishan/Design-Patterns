Simple Implementation of Singleton Design Pattern

NOTE: In our code we are fetching data from the database with the help of Singleton object.

What is the problem with Basic Singleton?

We are tied to the actual database, so when we get a productiond database and when we expect data from
that database.

This emplies that our tests is not a unit test. It is unfortunately an integration test.

How? -> We wanted to test the singleton record find operation not the operation of the database. Its all
due to the strong coupling to the singleton database.
