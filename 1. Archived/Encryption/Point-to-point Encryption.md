標籤: #Encryption

---

[TOC]

---

Point-to-point encryption is a standard established by the [[PCI Security Standards Council]]. This standards implies what should payment solutions providers do to maximize the security of payment. There are several solution providers, listed here: [Point-to-Point Encryption Solutions - pci council](https://www.pcisecuritystandards.org/assessors_and_solutions/point_to_point_encryption_solutions).

Point-to-point encryption is also called P2PE.

Payment solutions that offer similar encryption but do not meet the standard is called ==end-to-end encryption==.

# How it works?

The example of the whole process is described below:

1. Payment card swipe through a device. This device is called a ==point of interaction (POI)== device.
2. POI immediately encrypts the card information. This means that the POI should be able to perform a hardware-based encryption.

> The key for encryption and decryption is never available to the merchant, making the data invisible to the retailer.

3. Encrypted, indecipherable codes are sent to the payment gateway or the processor for decryption.
4. The decrypted code is sent to the bank. The bank will approve or reject the transaction.
5. The bank notifies the merchant whether the transaction is successful or not. The merchant is given a token to track the progress of the transaction.

> The token is a unique number reference, and the merchant can't know any personnel information with it.

---

參考資料:

[Point-to-Point Encryption - wiki](https://en.wikipedia.org/wiki/Point-to-point_encryption)

---

link:

