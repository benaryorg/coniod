# W.I.P.

It is very unlikely that the daemon is usable when you are reading this.
Please keep a close look at the changelogs in case you are interested in actually putting this to
use.

# coniod

The Connect IO Daemon or short *coniod* is a daemon used to connect arbitrary processes with one
another.
This way you can spawn multiple processes and arbitraryly connect them using pipes.
You can start a webserver, let it log to stdout and send that output to OpenSSL and stream it to a
different machine to store the logs.
If you want to get really fancy, why not encrypt using GPG, base64 the output for better
transferability, and send over the wire using netcat?
Furthermore it's possible to connect multiple processes to another one's output in a tee-like
fashion, that way you can effectively stream to multiple servers at the same time, or write to a
file and send over the wire.
The possibilities are endless.

