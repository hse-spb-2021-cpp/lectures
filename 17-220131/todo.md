thread_local is a whole separate topic, new kind of storage duration
networking: do not use `send`/`recv` assuming you "parse packets of TCP messages" (e.g. you may receive multiple messages in the same packet, or it may be split; the former looks like data loss, the latter looks like data corruption)
