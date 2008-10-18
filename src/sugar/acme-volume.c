/* acme-volume.c

   Copyright (C) 2002, 2003 Bastien Nocera

   The Gnome Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The Gnome Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the Gnome Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.

   Author: Bastien Nocera <hadess@hadess.net>
 */

#ifdef HAVE_CONFIG
#include "config.h"
#endif
#include "acme-volume.h"
#ifdef HAVE_OSS
#include "acme-volume-oss.h"
#endif
#ifdef HAVE_ALSA
#include "acme-volume-alsa.h"
#endif
#ifdef HAVE_GSTREAMER
#include "acme-volume-gstreamer.h"
#endif

G_DEFINE_TYPE (AcmeVolume, acme_volume, G_TYPE_OBJECT)

static void
acme_volume_class_init (AcmeVolumeClass *klass)
{
}

static void
acme_volume_init (AcmeVolume *vol)
{
}

int
acme_volume_get_volume (AcmeVolume *self)
{
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (ACME_IS_VOLUME (self), 0);

	return ACME_VOLUME_GET_CLASS (self)->get_volume (self);
}

void
acme_volume_set_volume (AcmeVolume *self, int val)
{
	g_return_if_fail (self != NULL);
	g_return_if_fail (ACME_IS_VOLUME (self));

	ACME_VOLUME_GET_CLASS (self)->set_volume (self, val);
}

gboolean
acme_volume_get_mute (AcmeVolume *self)
{
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (ACME_IS_VOLUME (self), FALSE);

	return ACME_VOLUME_GET_CLASS (self)->get_mute (self);
}

void
acme_volume_set_mute (AcmeVolume *self, gboolean val)
{
	g_return_if_fail (self != NULL);
	g_return_if_fail (ACME_IS_VOLUME (self));

	ACME_VOLUME_GET_CLASS (self)->set_mute (self, val);
}

void
acme_volume_mute_toggle (AcmeVolume *self)
{
	gboolean muted;

	g_return_if_fail (self != NULL);
	g_return_if_fail (ACME_IS_VOLUME (self));

	muted = ACME_VOLUME_GET_CLASS (self)->get_mute (self);
	ACME_VOLUME_GET_CLASS (self)->set_mute (self, !muted);
}

int
acme_volume_get_threshold (AcmeVolume *self)
{
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (ACME_IS_VOLUME (self), 0);

	return ACME_VOLUME_GET_CLASS (self)->get_threshold (self);
}

AcmeVolume *acme_volume_new (void)
{
	AcmeVolume *vol;

#ifdef HAVE_GSTREAMER
	vol = ACME_VOLUME (g_object_new (acme_volume_gstreamer_get_type (), NULL));
	return vol;
#endif
#ifdef HAVE_ALSA
	vol = ACME_VOLUME  (g_object_new (acme_volume_alsa_get_type (), NULL));
	if (vol != NULL && ACME_VOLUME_ALSA (vol)->_priv != NULL)
		return vol;
	if (ACME_VOLUME_ALSA (vol)->_priv == NULL)
		g_object_unref (vol);
#endif
#ifdef HAVE_OSS
	vol = ACME_VOLUME  (g_object_new (acme_volume_oss_get_type (), NULL));
	return vol;
#endif
	return NULL;
}

