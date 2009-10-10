/*
 * This file is part of the SSH Library
 *
 * Copyright (c) 2009 by Aris Adamantiadis
 *
 * The SSH Library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or (at your
 * option) any later version.
 *
 * The SSH Library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with the SSH Library; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 * MA 02111-1307, USA.
 */

#ifndef MISC_H_
#define MISC_H_

/* in misc.c */
/* gets the user home dir. */
char *ssh_get_user_home_dir(void);
int ssh_file_readaccess_ok(const char *file);

/* macro for byte ordering */
uint64_t ntohll(uint64_t);
#define htonll(x) ntohll(x)

/* list processing */

struct ssh_list {
  struct ssh_iterator *root;
  struct ssh_iterator *end;
};

struct ssh_iterator {
  struct ssh_iterator *next;
  const void *data;
};

struct ssh_list *ssh_list_new(void);
void ssh_list_free(struct ssh_list *list);
struct ssh_iterator *ssh_list_get_iterator(const struct ssh_list *list);
int ssh_list_add(struct ssh_list *list, const void *data);
void ssh_list_remove(struct ssh_list *list, struct ssh_iterator *iterator);

/** @brief fetch the head element of a list and remove it from list
 * @param list the ssh_list to use
 * @return the first element of the list
 */
const void *_ssh_list_get_head(struct ssh_list *list);

#define ssh_iterator_value(type, iterator)\
  ((type)((iterator)->data))

/** @brief fetch the head element of a list and remove it from list
 * @param type type of the element to return
 * @param list the ssh_list to use
 * @return the first element of the list
 */
#define ssh_list_get_head(type, ssh_list)\
  ((type)_ssh_list_get_head(ssh_list))

#endif /* MISC_H_ */