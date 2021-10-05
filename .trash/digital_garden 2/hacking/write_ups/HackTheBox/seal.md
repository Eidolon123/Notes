/admin
/css 
/host-manager
/images     
/index.html        
/js
/manager  

If-Modified-Since: Wed, 05 May 2021 13:26:30 GMT

![[admin_reserved.png]]

```
	ToDo:
    Remove mutual authentication for dashboard, setup registration and login features.
    Deploy updated tomcat configuration.
    Disable manager and host-manager.
```

nginx 1.18.0

https://10.10.10.250 -H X-rewrite-url: manager/status/..;/text