Tag: #SDN 
Previous: [[ryu SDN framework]]
Link: 

[TOC]

---

When running a simple ryu controller python script:

```python
from ryu.base import app_manager
from ryu.ofproto import ofproto_v1_3

class SimpleSwitch(app_manager.RyuApp):
    OFP_VERSIONS = [ofproto_v1_3.OFP_VERSION]

    def __init__(self,*args,**kwargs):
        super(SimpleSwitch,self).__init__(*args,**kwargs)
```

Two problems appears:

- [[#Problem 1 eventlet problem]]
- [[#Problem 2 DNS]]

# Problem 1: eventlet problem

Following problem about `eventlet`, a pip package appears:

```
Traceback (most recent call last):
  File "simple-switch.py", line 1, in <module>
    from ryu.base import app_manager
  File "/home/p4/.local/lib/python3.8/site-packages/ryu/base/app_manager.py", line 35, in <module>
    from ryu.app import wsgi
  File "/home/p4/.local/lib/python3.8/site-packages/ryu/app/wsgi.py", line 109, in <module>
    class _AlreadyHandledResponse(Response):
  File "/home/p4/.local/lib/python3.8/site-packages/ryu/app/wsgi.py", line 111, in _AlreadyHandledResponse
    from eventlet.wsgi import ALREADY_HANDLED
ImportError: cannot import name 'ALREADY_HANDLED' from 'eventlet.wsgi' (/home/p4/.local/lib/python3.8/site-packages/eventlet/wsgi.py)
```

On stackoverflow, [Eventlet Problem - stackoverflow](https://stackoverflow.com/questions/67409452/gunicorn-importerror-cannot-import-name-already-handled-from-eventlet-wsgi) states that there are two versions that can be used to remedy this problem:

```sh
pip install eventlet==0.30.2
```

or

```sh
pip install eventlet==0.33.0 https://github.com/benoitc/gunicorn/archive/refs/heads/master.zip#egg=gunicorn==20.1.0
```

> Only `0.30.2` works.

# Problem 2: dnspython problem

Upon solving the first problem, the second problem occasionally appears:

```
Traceback (most recent call last):
  File "simple-switch.py", line 1, in <module>
    from ryu.base import app_manager
  File "/home/p4/.local/lib/python3.8/site-packages/ryu/base/app_manager.py", line 35, in <module>
    from ryu.app import wsgi
  File "/home/p4/.local/lib/python3.8/site-packages/ryu/app/wsgi.py", line 35, in <module>
    from ryu.lib import hub
  File "/home/p4/.local/lib/python3.8/site-packages/ryu/lib/hub.py", line 30, in <module>
    import eventlet
  File "/home/p4/.local/lib/python3.8/site-packages/eventlet/__init__.py", line 17, in <module>
    from eventlet import convenience
  File "/home/p4/.local/lib/python3.8/site-packages/eventlet/convenience.py", line 7, in <module>
    from eventlet.green import socket
  File "/home/p4/.local/lib/python3.8/site-packages/eventlet/green/socket.py", line 21, in <module>
    from eventlet.support import greendns
  File "/home/p4/.local/lib/python3.8/site-packages/eventlet/support/greendns.py", line 66, in <module>
    setattr(dns, pkg, import_patched('dns.' + pkg))
  File "/home/p4/.local/lib/python3.8/site-packages/eventlet/support/greendns.py", line 61, in import_patched
    return patcher.import_patched(module_name, **modules)
  File "/home/p4/.local/lib/python3.8/site-packages/eventlet/patcher.py", line 132, in import_patched
    return inject(
  File "/home/p4/.local/lib/python3.8/site-packages/eventlet/patcher.py", line 109, in inject
    module = __import__(module_name, {}, {}, module_name.split('.')[:-1])
  File "/home/p4/.local/lib/python3.8/site-packages/dns/zone.py", line 85, in <module>
    class Zone(dns.transaction.TransactionManager):
  File "/home/p4/.local/lib/python3.8/site-packages/dns/zone.py", line 756, in Zone
    ) -> dns.rdtypes.ANY.SOA.SOA:
AttributeError: module 'dns.rdtypes' has no attribute 'ANY'
```

[DNS python Problem - stackoverflow](https://stackoverflow.com/questions/75137717/eventlet-dns-python-attribute-error-module-dns-rdtypes-has-no-attribute-any) states that it can be solved by using `dnspython` version `2.2.1`:

```sh
python3 -m pip install dnspython==2.2.1
```

---

# Reference

[Eventlet Problem - stackoverflow](https://stackoverflow.com/questions/67409452/gunicorn-importerror-cannot-import-name-already-handled-from-eventlet-wsgi)
[DNS python Problem - stackoverflow](https://stackoverflow.com/questions/75137717/eventlet-dns-python-attribute-error-module-dns-rdtypes-has-no-attribute-any)

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.