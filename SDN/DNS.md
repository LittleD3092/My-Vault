Tag: #SDN 
Previous: 
Link: [[DHCP]]

[TOC]

---

- DNS stands for "domain name system".
- This service translate domain names into IP addresses.

# DNS PTR record

A DNS PTR record (DNS pointer record) is a record that maps IP addresses to domain names.

```
192.0.2.1 -> host.example.com
```

- DNS PTR records are maintained by the organizations that controls the IP address space. (ISPs, hosting providers...)

# NS record

NS record stands for **namespace record**. NS records point to the servers that will **answer DNS queries** for a domain.

For example:

```
example.com.   NS   ns1.example-dns-provider.com.
example.com.   NS   ns2.example-dns-provider.com.
```

# MX-record

MX stands for **mail exchange**. This query fetches MX records for a domain.

The basic steps of querying is as follows:

1. A client uses MX-record query to find out where to deliver an email for a **specific domain** `example.com`.
2. The DNS system returns **a list of mail servers**, with priorities.
3. The client uses this information to **connect to the highest priority mail server**.
4. The client may fall back to lower priority servers if needed.

A MX-record might look like this:

```yaml
Priority: 10
Mail server: mail1.example.com

Priority: 20
Mail server: mail2.example.com
```

---

# Reference

[Domain Name System - wiki](https://en.wikipedia.org/wiki/Domain_Name_System)

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.