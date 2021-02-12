/*
  The role is a concept of PostgreSQL for database access permission management.
  A role can be a user or a group, depending on how you setup the role.
  The role with login rights is called user.
  A role that keeps the other roles is named group.

  Database roles are global across a database cluster. It is completely separate
  from operating system users.

  The attributes of a database role defines the privileges.
  LOGIN
  PASSWORD
  SUPERUSER
  CREATEDB
  CREATEROLE
  REPLICATION

  The members of group can use the privileges of the role in two ways.
  SET ROLE "temporarily become the group role, rather then original."
  INHERIT "role that have this attribute automatically have use the privileges
           of roles of which they are members."
  RESET ROLE "Restore the original privilege."

 */

-- The new role/group creation.
CREATE ROLE test_role;

-- Getting all roles in the cluster.
SELECT
  rolname
FROM
  pg_roles;

-- Creating roles with privileges login, password, and valid date.
CREATE ROLE test_user
WITH PASSWORD
  'password123'
LOGIN
VALID UNTIL
  '2020-05-08';

-- Creating a roles and addition them to the group.
CREATE ROLE test_user_1;

CREATE ROLE test_user_2
WITH PASSWORD
  '1234'
LOGIN
CREATEDB;

GRANT test_role to test_user_1;
GRANT test_role to test_user_2;

-- Removing user from a group.
REVOKE test_role FROM test_user_1;

-- Group privileges.
CREATE ROLE test_user_3 LOGIN NOINHERIT;
CREATE ROLE test_role_2 LOGIN NOINHERIT;
CREATE ROLE test_role_3 LOGIN INHERIT;
GRANT test_role_2 to test_user_3;
GRANT test_role_3 to test_user;

-- Role removing.
DROP ROLE test_role;
DROP ROLE test_role_2;
DROP ROLE test_role_3;
DROP ROLE test_user;
DROP ROLE test_user_1;
DROP ROLE test_user_2;
DROP ROLE test_user_3;

