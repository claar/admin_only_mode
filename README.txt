This module provides a less-disruptive alternative to placing your site in 
full maintenance mode.
 
It allows you to place your site into an admin-only mode, so that only the
user with uid 1 is able to login.  All other users are logged out automatically
and cannot login again until the site leaves admin-only mode.

Anonymous users are unaffected by this mode.  If you need to stop anonymous users
from posting comments or other actions, you should consider the readonlymode or
mode modules instead of or in addition to this module.

To use this module, simply install it and either:
* Enable it on the maintenance settings page (admin/settings/site-maintenance).
  -or-
* Run drush admin-only-mode 1

Many thanks to the readonlymode module for the coding examples.

AUTHOR/MAINTAINER
======================
-Ben Claar
ben at claar DOT net
