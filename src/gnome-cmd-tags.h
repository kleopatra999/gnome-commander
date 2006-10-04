/*
    GNOME Commander - A GNOME based file manager
    Copyright (C) 2001-2006 Marcus Bjurman

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
*/

#ifndef __GNOME_CMD_TAGS_H__
#define __GNOME_CMD_TAGS_H__

#include <config.h>

#include "gnome-cmd-file.h"

G_BEGIN_DECLS

typedef enum {
    TAG_FILE  = -1,
    TAG_CHM   = 1 << 6,
    TAG_EXIF  = 1 << 7,
    TAG_IPTC  = 1 << 8,
    TAG_ICC   = 1 << 9,
    TAG_ID3   = 1 << 10,
    TAG_RPM   = 1 << 11,
    TAG_AUDIO = TAG_ID3+1,
    TAG_DOC   = TAG_CHM+1,
    TAG_IMAGE = TAG_EXIF | TAG_IPTC | TAG_ICC
} GnomeCmdTagClass;


typedef enum {
    TAG_NONE,
    TAG_AUDIO_ALBUMARTIST,                  // artist of the album
    TAG_AUDIO_ALBUMGAIN,                    // gain adjustment of album
    TAG_AUDIO_ALBUMPEAKGAIN,                // peak gain adjustment of album
    TAG_AUDIO_ALBUMTRACKCOUNT,              // total no. of tracks on the album
    TAG_AUDIO_ALBUM,                        // name of the album
    TAG_AUDIO_ARTIST,                       // artist of the track
    TAG_AUDIO_BITRATE,                      // bitrate in kbps
    TAG_AUDIO_CHANNELS,                     // number of channels in the audio (2 = stereo)
    TAG_AUDIO_CODECVERSION,                 // codec version
    TAG_AUDIO_CODEC,                        // codec encoding description
    TAG_AUDIO_COMMENT,                      // comments on the track
    TAG_AUDIO_COVERALBUMTHUMBNAILPATH,      // file path to thumbnail image of the cover album
    TAG_AUDIO_DISCNO,                       // specifies which disc the track is on
    TAG_AUDIO_DURATION,                     // duration of track in seconds
    TAG_AUDIO_GENRE,                        // type of music classification for the track as defined in ID3 spec
    TAG_AUDIO_ISNEW,                        // set to "1" if track is new to the user (default "0")
    TAG_AUDIO_LASTPLAY,                     // when track was last played
    TAG_AUDIO_LYRICS,                       // lyrics of the track
    TAG_AUDIO_MBALBUMARTISTID,              // musicBrainz album artist ID in UUID format
    TAG_AUDIO_MBALBUMID,                    // musicBrainz album ID in UUID format
    TAG_AUDIO_MBARTISTID,                   // musicBrainz artist ID in UUID format
    TAG_AUDIO_MBTRACKID,                    // musicBrainz track ID in UUID format
    TAG_AUDIO_PERFORMER,                    // name of the performer/conductor of the music
    TAG_AUDIO_PLAYCOUNT,                    // number of times the track has been played
    TAG_AUDIO_RELEASEDATE,                  // date track was released
    TAG_AUDIO_SAMPLERATE,                   // samplerate in Hz
    TAG_AUDIO_TITLE,                        // title of the track
    TAG_AUDIO_TRACKGAIN,                    // gain adjustment of track
    TAG_AUDIO_TRACKNO,                      // position of track on the album
    TAG_AUDIO_TRACKPEAKGAIN,                // peak gain adjustment of track
    TAG_DOC_AUTHOR,                         // name of the author
    TAG_DOC_COMMENTS,                       // user definable free text
    TAG_DOC_CREATED,                        // datetime document was originally
    TAG_DOC_KEYWORDS,                       // string of keywords
    TAG_DOC_PAGECOUNT,                      // no. of pages in document
    TAG_DOC_SUBJECT,                        // document subject
    TAG_DOC_TITLE,                          // title of document
    TAG_DOC_WORDCOUNT,                      // total no. of chars in document
    TAG_EXIF_APERTUREVALUE,                 // lens aperture
    TAG_EXIF_ARTIST,                        // person who created the image
    TAG_EXIF_BATTERYLEVEL,                  // battery level
    TAG_EXIF_BITSPERSAMPLE,                 // number of bits per component
    TAG_EXIF_BRIGHTNESSVALUE,               // value of brightness
    TAG_EXIF_CFAPATTERN,                    // color filter array (CFA) geometric pattern of the image sensor when a one-chip color area sensor is used
    TAG_EXIF_CFAREPEATPATTERNDIM,
    TAG_EXIF_COLORSPACE,                    // color space information
    TAG_EXIF_COMPONENTSCONFIGURATION,       // information specific to compressed data. The channels of each component are arranged in order from the 1st component to the 4th. For uncompressed data the data arrangement is given in the <PhotometricInterpretation> tag. However, since <PhotometricInterpretation> can only express the order of Y, Cb and Cr, is provided for cases when compressed data uses components other than Y, Cb, and Cr and to enable support of other sequences
    TAG_EXIF_COMPRESSEDBITSPERPIXEL,        // information specific to compressed data. The compression mode used for a compressed image is indicated in unit bits per pixel
    TAG_EXIF_COMPRESSION,                   // compression scheme
    TAG_EXIF_CONTRAST,                      // direction of contrast processing applied by the camera
    TAG_EXIF_COPYRIGHT,                     // copyright holder
    TAG_EXIF_CUSTOMRENDERED,                // use of special processing on image data, such as rendering geared to output. When special processing is performed, the reader is expected to disable or minimize any further processing
    TAG_EXIF_DATETIME,                      // file change date and time
    TAG_EXIF_DATETIMEDIGITIZED,             // date and time when the image was stored as digital data
    TAG_EXIF_DATETIMEORIGINAL,              // date and time when the original image data was generated
    TAG_EXIF_DEVICESETTINGDESCRIPTION,      // information on the picture-taking conditions of a particular camera model
    TAG_EXIF_DIGITALZOOMRATIO,              // digital zoom ratio If the numerator of the recorded value is 0, this indicates that digital zoom was not used
    TAG_EXIF_DOCUMENTNAME,
    TAG_EXIF_EXIFIFDPOINTER,                // pointer to the Exif IFD
    TAG_EXIF_EXIFVERSION,                   // Exif standard version
    TAG_EXIF_EXPOSUREBIASVALUE,             // exposure bias
    TAG_EXIF_EXPOSUREINDEX,                 // exposure index
    TAG_EXIF_EXPOSUREMODE,                  // exposure mode set In auto-bracketing mode, the camera shoots a series of frames of the same scene at different exposure settings
    TAG_EXIF_EXPOSUREPROGRAM,               // class of the program used by the camera to set exposure when the picture is taken
    TAG_EXIF_EXPOSURETIME,                  // exposure time, given in seconds (sec)
    TAG_EXIF_FILESOURCE,                    // image source
    TAG_EXIF_FILLORDER,
    TAG_EXIF_FLASH,                         // is recorded when an image is taken using a strobe light (flash)
    TAG_EXIF_FLASHENERGY,                   // strobe energy at the time the image is captured, as measured in Beam Candle Power Seconds (BCPS)
    TAG_EXIF_FLASHPIXVERSION,               // FlashPix format version supported by a FPXR file
    TAG_EXIF_FNUMBER,                       // F number
    TAG_EXIF_FOCALLENGTH,                   // actual focal length of the lens, in mm. Conversion is not made to the focal length of a 35 mm film camera
    TAG_EXIF_FOCALLENGTHIN35MMFILM,         // equivalent focal length assuming a 35mm film camera, in mm. A value of 0 means the focal length is unknown. Note that differs from the FocalLength tag
    TAG_EXIF_FOCALPLANERESOLUTIONUNIT,      // unit for measuring <FocalPlaneXResolution> and <FocalPlaneYResolution>. This value is the same as the <ResolutionUnit>
    TAG_EXIF_FOCALPLANEXRESOLUTION,         // number of pixels in the image width (X) direction per <FocalPlaneResolutionUnit> on the camera focal plane
    TAG_EXIF_FOCALPLANEYRESOLUTION,         // number of pixels in the image height (V) direction per <FocalPlaneResolutionUnit> on the camera focal plane
    TAG_EXIF_GAINCONTROL,                   // degree of overall image gain adjustment
    TAG_EXIF_GAMMA,                         // value of coefficient gamma
    TAG_EXIF_GPSALTITUDE,                   // altitude based on the reference in GPSAltitudeRef. Altitude is expressed as one RATIONAL value. The reference unit is meters
    TAG_EXIF_GPSALTITUDEREF,                // altitude used as the reference altitude. If the reference is sea level and the altitude is above sea level, 0 is given. If the altitude is below sea level, a value of 1 is given and the altitude is indicated as an absolute value in the GSPAltitude tag. The reference unit is meters. Note that is BYTE type, unlike other reference tags
    TAG_EXIF_GPSINFOIFDPOINTER,             // pointer to the GPS Info IFD
    TAG_EXIF_GPSLATITUDE,                   // latitude. The latitude is expressed as three RATIONAL values giving the degrees, minutes, and seconds, respectively. When degrees, minutes and seconds are expressed, the format is dd/1,mm/1,ss/1. When degrees and minutes are used and, for example, fractions of minutes are given up to two decimal places, the format is dd/1,mmmm/100,0/1
    TAG_EXIF_GPSLATITUDEREF,                // latitude indicator ('N' indicates north, 'S' - south latitude)
    TAG_EXIF_GPSLONGITUDE,                  // longitude
    TAG_EXIF_GPSLONGITUDEREF,               // Indicates whether the longitude is east or west longitude. ASCII 'E' indicates east longitude, and 'W' is west longitude
    TAG_EXIF_GPSVERSIONID,                  // version of <GPSInfoIFD>
    TAG_EXIF_IMAGEDESCRIPTION,              // image title
    TAG_EXIF_IMAGELENGTH,                   // image height
    TAG_EXIF_IMAGERESOURCES,
    TAG_EXIF_IMAGEUNIQUEID,                 // indicates an identifier assigned uniquely to each image. It is recorded as an ASCII string equivalent to hexadecimal notation and 128-bit fixed length
    TAG_EXIF_IMAGEWIDTH,                    // image width
    TAG_EXIF_INTERCOLORPROFILE,             // color profile
    TAG_EXIF_INTEROPERABILITYIFDPOINTER,    // interoperability IFD is composed of tags which stores the information to ensure the Interoperability and pointed by the following tag located in Exif IFD. The Interoperability structure of Interoperability IFD is the same as TIFF defined IFD structure but does not contain the image data characteristically compared with normal TIFF IFD
    TAG_EXIF_INTEROPERABILITYINDEX,         // identification of the Interoperability rule. Use \"R98\" for stating ExifR98 Rules. Four bytes used including the termination code (NULL). see the separate volume of Recommended Exif Interoperability Rules (ExifR98) for other tags used for ExifR98
    TAG_EXIF_INTEROPERABILITYVERSION,
    TAG_EXIF_IPTCNAA,
    TAG_EXIF_ISOSPEEDRATINGS,               // ISO Speed and ISO Latitude of the camera or input device as specified in ISO 12232
    TAG_EXIF_JPEGINTERCHANGEFORMAT,         // offset to JPEG SOI
    TAG_EXIF_JPEGINTERCHANGEFORMATLENGTH,   // bytes of JPEG data
    TAG_EXIF_JPEGPROC,
    TAG_EXIF_LIGHTSOURCE,                   // kind of light source
    TAG_EXIF_MAKE,                          // image input equipment manufacturer
    TAG_EXIF_MAKERNOTE,                     // tag for manufacturers of Exif writers to record any desired information. The contents are up to the manufacturer
    TAG_EXIF_MAXAPERTUREVALUE,              // smallest F number of the lens
    TAG_EXIF_METERINGMODE,                  // metering mode
    TAG_EXIF_MODEL,                         // image input equipment model
    TAG_EXIF_NEWCFAPATTERN,                 // color filter array (CFA) geometric pattern of the image sensor when a one-chip color area sensor is used. It does not apply to all sensing methods
    TAG_EXIF_NEWSUBFILETYPE,                // general indication of the kind of data contained in this subfile
    TAG_EXIF_OECF,                          // Opto-Electoric Conversion Function (OECF) specified in ISO 14524
    TAG_EXIF_ORIENTATION,                   // orientation of image
    TAG_EXIF_PHOTOMETRICINTERPRETATION,     // pixel composition
    TAG_EXIF_PIXELXDIMENSION,               // Information specific to compressed data. When a compressed file is recorded, the valid width of the meaningful image must be recorded in this tag, whether or not there is padding data or a restart marker. should not exist in an uncompressed file
    TAG_EXIF_PIXELYDIMENSION,               // Information specific to compressed data. When a compressed file is recorded, the valid height of the meaningful image must be recorded in this tag, whether or not there is padding data or a restart marker. should not exist in an uncompressed file
    TAG_EXIF_PLANARCONFIGURATION,           // image data arrangement
    TAG_EXIF_PRIMARYCHROMATICITIES,         // chromaticities of primaries
    TAG_EXIF_REFERENCEBLACKWHITE,           // pair of black and white reference values
    TAG_EXIF_RELATEDIMAGEFILEFORMAT,
    TAG_EXIF_RELATEDIMAGELENGTH,
    TAG_EXIF_RELATEDIMAGEWIDTH,
    TAG_EXIF_RELATEDSOUNDFILE,              // name of an audio file related to the image data
    TAG_EXIF_RESOLUTIONUNIT,                // unit of X and Y resolution
    TAG_EXIF_ROWSPERSTRIP,                  // number of rows per strip
    TAG_EXIF_SAMPLESPERPIXEL,               // number of components
    TAG_EXIF_SATURATION,                    // direction of saturation processing applied by the camera
    TAG_EXIF_SCENECAPTURETYPE,              // capture type of scene
    TAG_EXIF_SCENETYPE,                     // type of scene
    TAG_EXIF_SENSINGMETHOD,                 // image sensor type on the camera or input device
    TAG_EXIF_SHARPNESS,                     // direction of sharpness processing applied by the camera
    TAG_EXIF_SHUTTERSPEEDVALUE,             // shutter speed
    TAG_EXIF_SOFTWARE,                      // software used
    TAG_EXIF_SPATIALFREQUENCYRESPONSE,      // camera or input device spatial frequency table and SFR values in the direction of image width, image height, and diagonal direction, as specified in ISO 12233
    TAG_EXIF_SPECTRALSENSITIVITY,           // spectral sensitivity of each channel of the camera used. The tag value is an ASCII string compatible with the standard developed by the ASTM Technical Committee
    TAG_EXIF_STRIPBYTECOUNTS,               // bytes per compressed strip
    TAG_EXIF_STRIPOFFSETS,                  // image data location
    TAG_EXIF_SUBIFDS,                       // defined by Adobe Corporation to enable TIFF Trees within a TIFF file
    TAG_EXIF_SUBJECTAREA,                   // location and area of the main subject in the overall scene
    TAG_EXIF_SUBJECTDISTANCE,               // distance to the subject, given in meters
    TAG_EXIF_SUBJECTDISTANCERANGE,          // distance to the subject
    TAG_EXIF_SUBJECTLOCATION,               // location of the main subject in the scene. The value of represents the pixel at the center of the main subject relative to the left edge, prior to rotation processing as per the <Rotation> tag. The first value X column number and second Y row number
    TAG_EXIF_SUBSECTIME,                    // fractions of seconds for the <DateTime> tag
    TAG_EXIF_SUBSECTIMEDIGITIZED,           // fractions of seconds for the <DateTimeDigitized> tag
    TAG_EXIF_SUBSECTIMEORIGINAL,            // fractions of seconds for the <DateTimeOriginal> tag
    TAG_EXIF_TIFFEPSTANDARDID,
    TAG_EXIF_TRANSFERFUNCTION,              // transfer function for the image, described in tabular style
    TAG_EXIF_TRANSFERRANGE,
    TAG_EXIF_USERCOMMENT,                   // user comments
    TAG_EXIF_WHITEBALANCE,                  // white balance mode set
    TAG_EXIF_WHITEPOINT,                    // white point chromaticity
    TAG_EXIF_XMLPACKET,                     // XMP Metadata
    TAG_EXIF_XRESOLUTION,                   // image resolution in width direction
    TAG_EXIF_YCBCRCOEFFICIENTS,             // color space transformation matrix coefficients
    TAG_EXIF_YCBCRPOSITIONING,              // Y and C positioning
    TAG_EXIF_YCBCRSUBSAMPLING,              // subsampling ratio of Y to C
    TAG_EXIF_YRESOLUTION,                   // image resolution in height direction
    TAG_FILE_ACCESSED,                      // last access datetime
    TAG_FILE_CONTENT,                       // file's contents filtered as plain text (IE as stored by the indexer)
    TAG_FILE_DESCRIPTION,                   // editable free text/notes
    TAG_FILE_FORMAT,                        // mime type of the file or if a directory it should contain value "Folder"
    TAG_FILE_ICONPATH,                      // editable file uri for a custom icon for the file
    TAG_FILE_KEYWORDS,                      // editable array of keywords
    TAG_FILE_LARGETHUMBNAILPATH,            // editable file uri for a larger thumbnail of the file suitable for previews
    TAG_FILE_LINK,                          // URI of link target
    TAG_FILE_MODIFIED,                      // last modified datetime
    TAG_FILE_NAME,                          // file name excluding path but including the file extension
    TAG_FILE_PATH,                          // full file path of file excluding the filename
    TAG_FILE_PERMISSIONS,                   // permission string in unix format eg "-rw-r--r--"
    TAG_FILE_PUBLISHER,                     // editable DC type for the name of the publisher of the file (EG dc:publisher field in RSS feed)
    TAG_FILE_RANK,                          // editable file rank for grading favourites. Value should be in the range 1..10
    TAG_FILE_SIZE,                          // size of the file in bytes or if a directory no. of items it contains
    TAG_FILE_SMALLTHUMBNAILPATH,            // editable file uri for a small thumbnail of the file suitable for use in icon views
    TAG_IMAGE_ALBUM,                        // name of an album the image belongs to
    TAG_IMAGE_CAMERAMAKE,                   // make of camera used to take the image
    TAG_IMAGE_CAMERAMODEL,                  // model of camera used to take the image
    TAG_IMAGE_COMMENTS,                     // user definable free text
    TAG_IMAGE_COPYRIGHT,                    // embedded copyright message
    TAG_IMAGE_CREATOR,                      // name of the author
    TAG_IMAGE_DATE,                         // datetime image was originally created
    TAG_IMAGE_DESCRIPTION,                  // description of the image
    TAG_IMAGE_EXPOSUREPROGRAM,              // the program used by the camera to set exposure when the picture is taken. EG Manual, Normal, Aperture priority etc
    TAG_IMAGE_EXPOSURETIME,                 // exposure time used to capture the photo in seconds
    TAG_IMAGE_FLASH,                        // set to 1 if flash was fired
    TAG_IMAGE_FNUMBER,                      // diameter of the aperture relative to the effective focal length of the lens.
    TAG_IMAGE_FOCALLENGTH,                  // focal length of lens in mm
    TAG_IMAGE_HEIGHT,                       // height in pixels
    TAG_IMAGE_ISOSPEED,                     // ISO speed used to acquire the document contents. For example, 100, 200, 400, etc.
    TAG_IMAGE_KEYWORDS,                     // string of keywords
    TAG_IMAGE_METERINGMODE,                 // metering mode used to acquire the image (IE Unknown, Average, CenterWeightedAverage, Spot, MultiSpot, Pattern, Partial)
    TAG_IMAGE_ORIENTATION,                  // represents the orientation of the image wrt camera IE "top,left" or "bottom,right"
    TAG_IMAGE_SOFTWARE,                     // software used to produce/enhance the image
    TAG_IMAGE_TITLE,                        // title of image
    TAG_IMAGE_WHITEBALANCE,                 // white balance setting of the camera when the picture was taken (auto or manual)
    TAG_IMAGE_WIDTH,                        // width in pixels
    TAG_IPTC_ACTIONADVISED,                 // type of action that this object provides to a previous object
    TAG_IPTC_ARMID,                         // Abstract Relationship Method (ARM)
    TAG_IPTC_ARMVERSION,                    // version of the Abstract Relationship Method (ARM)
    TAG_IPTC_AUDIODURATION,                 // running time of the audio data in the form HHMMSS
    TAG_IPTC_AUDIOOUTCUE,                   // content at the end of the audio data
    TAG_IPTC_AUDIOSAMPLINGRATE,             // sampling rate in Hz of the audio data
    TAG_IPTC_AUDIOSAMPLINGRES,              // number of bits in each audio sample
    TAG_IPTC_AUDIOTYPE,                     // number of channels and type of audio (music, text, etc.) in the object
    TAG_IPTC_BYLINE,                        // name of the creator of the object
    TAG_IPTC_BYLINETITLE,                   // title of the creator or creators of the object
    TAG_IPTC_CAPTION,                       // textual description of the data
    TAG_IPTC_CATEGORY,                      // subject of the object in the opinion of the provider (Deprecated)
    TAG_IPTC_CHARACTERSET,                  // control functions used for the announcement, invocation or designation of coded character sets
    TAG_IPTC_CITY,                          // city of object origin
    TAG_IPTC_CONFIRMEDDATASIZE,             // total size of the object data
    TAG_IPTC_CONTACT,                       // person or organization which can provide further background information on the object
    TAG_IPTC_CONTENTLOCCODE,                // code of a country/geographical location referenced by the content of the object
    TAG_IPTC_CONTENTLOCNAME,                // full, publishable name of a country/geographical location referenced by the content of the object
    TAG_IPTC_COPYRIGHTNOTICE,               // any necessary copyright notice
    TAG_IPTC_COUNTRYCODE,                   // code of the country/primary location where the object was created
    TAG_IPTC_COUNTRYNAME,                   // name of the country/primary location where the object was created
    TAG_IPTC_CREDIT,                        // provider of the object, not necessarily the owner/creator
    TAG_IPTC_DATECREATED,                   // date the intellectual content of the object was created rather than the date of the creation of the physical representation
    TAG_IPTC_DATESENT,                      // day the service sent the material
    TAG_IPTC_DESTINATION,                   // routing information
    TAG_IPTC_DIGITALCREATIONDATE,           // date when the digital representation of the object was created
    TAG_IPTC_DIGITALCREATIONTIME,           // time when the digital representation of the object was created
    TAG_IPTC_EDITORIALUPDATE,               // type of update this object provides to a previous object
    TAG_IPTC_EDITSTATUS,                    // status of the object, according to the practice of the provider
    TAG_IPTC_ENVELOPENUM,                   // number unique for the date in 1:70 and the service ID in 1:30
    TAG_IPTC_ENVELOPEPRIORITY,              // specifies the envelope handling priority and not the editorial urgency
    TAG_IPTC_EXPIRATIONDATE,                // designates the latest date the provider intends the object to be used
    TAG_IPTC_EXPIRATIONTIME,                // designates the latest time the provider intends the object to be used
    TAG_IPTC_FILEFORMAT,                    // file format of the data described by this metadata
    TAG_IPTC_FILEVERSION,                   // version of the file format
    TAG_IPTC_FIXTUREID,                     // objects that recur often and predictably, enabling users to immediately find or recall such an object
    TAG_IPTC_HEADLINE,                      // publishable entry providing a synopsis of the contents of the object
    TAG_IPTC_IMAGEORIENTATION,              // layout of the image area: 'P' for portrait, 'L' for landscape, and 'S' for square
    TAG_IPTC_IMAGETYPE,                     // data format of the image object
    TAG_IPTC_KEYWORDS,                      // used to indicate specific information retrieval words
    TAG_IPTC_LANGUAGEID,                    // major national language of the object, according to the 2-letter codes of ISO 639:1988
    TAG_IPTC_MAXOBJECTSIZE,                 // largest possible size of the object if the size is not known
    TAG_IPTC_MAXSUBFILESIZE,                // maximum size for a subfile dataset (8:10) containing a portion of the object data
    TAG_IPTC_MODELVERSION,                  // version of IIM part 1
    TAG_IPTC_OBJECTATTRIBUTE,               // defines the nature of the object independent of the subject
    TAG_IPTC_OBJECTCYCLE,                   // where 'a' is morning, 'p' is evening, 'b' is both
    TAG_IPTC_OBJECTNAME,                    // shorthand reference for the object
    TAG_IPTC_OBJECTSIZEANNOUNCED,           // total size of the object data if it is known
    TAG_IPTC_OBJECTTYPE,                    // distinguishes between different types of objects within the IIM
    TAG_IPTC_ORIGINATINGPROGRAM,            // type of program used to originate the object
    TAG_IPTC_ORIGTRANSREF,                  // a code representing the location of original transmission
    TAG_IPTC_PREVIEWDATA,                   // object preview data
    TAG_IPTC_PREVIEWFORMAT,                 // binary value indicating the file format of the object preview data in dataset 2:202
    TAG_IPTC_PREVIEWFORMATVER,              // version of the preview file format specified in 2:200
    TAG_IPTC_PRODUCTID,                     // product ID
    TAG_IPTC_PROGRAMVERSION,                // version of the originating program
    TAG_IPTC_PROVINCE,                      // Province/State where the object originates
    TAG_IPTC_RASTERIZEDCAPTION,             // contains rasterized object description and is used where characters that have not been coded are required for the caption
    TAG_IPTC_RECORDVERSION,                 // version of the IIM, Part 2
    TAG_IPTC_REFERENCEDATE,                 // date of a prior envelope to which the current object refers
    TAG_IPTC_REFERENCENUMBER,               // Envelope Number of a prior envelope to which the current object refers
    TAG_IPTC_REFERENCESERVICE,              // Service Identifier of a prior envelope to which the current object refers
    TAG_IPTC_RELEASEDATE,                   // designates the earliest date the provider intends the object to be used
    TAG_IPTC_RELEASETIME,                   // designates the earliest time the provider intends the object to be used
    TAG_IPTC_SERVICEID,                     // identifies the provider and product
    TAG_IPTC_SIZEMODE,                      // set to 0 if the size of the object is known and 1 if not known
    TAG_IPTC_SOURCE,                        // original owner of the intellectual content of the object
    TAG_IPTC_SPECIALINSTRUCTIONS,           // other editorial instructions concerning the use of the object
    TAG_IPTC_STATE,                         // Province/State where the object originates
    TAG_IPTC_SUBFILE,                       // object data itself
    TAG_IPTC_SUBJECTREFERENCE,              // structured definition of the subject matter
    TAG_IPTC_SUBLOCATION,                   // location within a city from which the object originates
    TAG_IPTC_SUPPLCATEGORY,                 // further refines the subject of the object (Deprecated)
    TAG_IPTC_TIMECREATED,                   // time the intellectual content of the object was created rather than the date of the creation of the physical representation
    TAG_IPTC_TIMESENT,                      // time the service sent the material
    TAG_IPTC_UNO,                           // eternal, globally unique identification for the object, independent of provider and for any media form
    TAG_IPTC_URGENCY,                       // specifies the editorial urgency of content and not necessarily the envelope handling priority
    TAG_IPTC_WRITEREDITOR,                  // name of the person involved in the writing, editing or correcting the object or caption/abstract
    NUMBER_OF_TAGS
} GnomeCmdTag;


GnomeCmdTag gcmd_tags_get_tag_by_long_name(const gchar *tag_name);
GnomeCmdTag gcmd_tags_get_tag_by_name(const GnomeCmdTagClass tag_class, const gchar *tag_name);
const gchar *gcmd_tags_get_name(GnomeCmdTag tag);
const gchar *gcmd_tags_get_class_name(GnomeCmdTag tag);
const gchar *gcmd_tags_get_value(GnomeCmdFile *finfo, GnomeCmdTag tag);
const gchar *gcmd_tags_get_value_by_long_name(GnomeCmdFile *finfo, const gchar *tag_name);
const gchar *gcmd_tags_get_value_by_name(GnomeCmdFile *finfo, GnomeCmdTagClass tag_class, const gchar *tag_name);
const gchar *gcmd_tags_get_title(GnomeCmdTag tag);
const gchar *gcmd_tags_get_description(GnomeCmdTag tag);

G_END_DECLS

#endif // __GNOME_CMD_TAGS_H__
