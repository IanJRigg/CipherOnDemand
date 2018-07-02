# Cipher on Demand
CipherOnDemand is a Qt UI application that I've used to learn the Qt framework.  It currently allows a user to encrypt and decrypt input based on two ciphers: Caesar, and Vignere.

## Design
CipherOnDemand is made without any QML, and is created entirely by the code itself. This reason for this decision stems from issues with the design of the Qt Layouts, and how they're represented in Qt Designer.

The Encryption algorithms are controlled in a top level wrapper object that exposes polymorphic references to the objects which implement the encryption algorithms, and which reference is provided is determined by the currently active tab.

## TODO:
1. Add a test suite. Unit tests for the algorithms, and integration tests for the UI itself.
2. Refactor the UI generation code to better represent the design as a tree.
3. Refactor the Caesar cipher to use the vigenere table.
4. Allow for users to enter a custom alphabet for the vigenere table. (Will definitely collide with number 3).

## Future Extensions:
1. Add a substitution cipher
2. Add a more modern cipher (e.g. 3 or 4 wheel Enigma)
3. Add an algorithm in present use.