-- phpMyAdmin SQL Dump
-- version 4.0.10.17
-- https://www.phpmyadmin.net
--
-- Host: ganjodbinstance.cvmoatm7juvm.us-west-2.rds.amazonaws.com
-- Generation Time: Jul 16, 2017 at 09:49 PM
-- Server version: 5.6.27-log
-- PHP Version: 5.6.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `low_main`
--

-- --------------------------------------------------------

--
-- Table structure for table `albums`
--

CREATE TABLE IF NOT EXISTS `albums` (
  `album_id` int(11) NOT NULL AUTO_INCREMENT,
  `client_id` int(11) NOT NULL,
  `user_id` int(11) NOT NULL,
  `name` varchar(64) NOT NULL,
  `description` mediumtext NOT NULL,
  `theme_id` int(11) NOT NULL,
  `music_id` int(11) NOT NULL,
  `cover_id` int(11) NOT NULL,
  `dt_added` datetime NOT NULL,
  PRIMARY KEY (`album_id`),
  KEY `client_id` (`client_id`),
  KEY `user_id` (`user_id`),
  KEY `dt_added` (`dt_added`),
  KEY `theme_id` (`theme_id`),
  KEY `music_id` (`music_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `albums`
--

INSERT INTO `albums` (`album_id`, `client_id`, `user_id`, `name`, `description`, `theme_id`, `music_id`, `cover_id`, `dt_added`) VALUES
(1, 1, 1, 'Kids', 'This is the pink album', 1, 0, 3, '2017-05-07 00:00:00'),
(2, 1, 1, 'Vacations', 'This is the green album', 2, 0, 1, '2017-05-07 04:00:00'),
(3, 1, 1, 'Aunt Lucy', 'This is the purple album', 3, 0, 2, '2017-05-07 10:00:00');

-- --------------------------------------------------------

--
-- Table structure for table `album_contents`
--

CREATE TABLE IF NOT EXISTS `album_contents` (
  `album_content_id` int(11) NOT NULL AUTO_INCREMENT,
  `album_id` int(11) NOT NULL,
  `content_id` int(11) NOT NULL,
  `display_order` int(11) NOT NULL,
  PRIMARY KEY (`album_content_id`),
  KEY `album_id` (`album_id`),
  KEY `content_id` (`content_id`),
  KEY `display_order` (`display_order`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Dumping data for table `album_contents`
--

INSERT INTO `album_contents` (`album_content_id`, `album_id`, `content_id`, `display_order`) VALUES
(1, 1, 1, 1),
(2, 1, 2, 2);

-- --------------------------------------------------------

--
-- Table structure for table `channels`
--

CREATE TABLE IF NOT EXISTS `channels` (
  `channel_id` int(11) NOT NULL AUTO_INCREMENT,
  `client_id` int(11) NOT NULL,
  `user_id` int(11) NOT NULL,
  `name` varchar(64) NOT NULL,
  `description` mediumtext NOT NULL,
  `theme_id` int(11) NOT NULL,
  `music_id` int(11) NOT NULL,
  `cover_id` int(11) NOT NULL,
  `dt_added` datetime NOT NULL,
  `active` int(11) NOT NULL,
  PRIMARY KEY (`channel_id`),
  KEY `client_id` (`client_id`),
  KEY `user_id` (`user_id`),
  KEY `dt_added` (`dt_added`),
  KEY `theme_id` (`theme_id`),
  KEY `music_id` (`music_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=12 ;

--
-- Dumping data for table `channels`
--

INSERT INTO `channels` (`channel_id`, `client_id`, `user_id`, `name`, `description`, `theme_id`, `music_id`, `cover_id`, `dt_added`, `active`) VALUES
(1, 1, 1, 'Summer Beach House', '', 1, 0, 1, '2017-05-07 00:00:00', 1),
(2, 1, 1, 'Lucy''s Day in the Park', '', 2, 0, 8, '2017-05-07 00:11:00', 1),
(3, 1, 1, '2013 Florida', '', 3, 0, 3, '2017-05-07 11:00:00', 1),
(11, 1, 1, 'Teachers Corner', '', 0, 0, 11, '2017-05-17 14:50:37', 1);

-- --------------------------------------------------------

--
-- Table structure for table `channel_content`
--

CREATE TABLE IF NOT EXISTS `channel_content` (
  `channel_content_id` int(11) NOT NULL AUTO_INCREMENT,
  `channel_id` int(11) NOT NULL,
  `channel_platform_id` int(11) NOT NULL,
  `title` varchar(128) NOT NULL,
  `summary` text NOT NULL,
  `image` varchar(64) NOT NULL,
  `dt_added` datetime NOT NULL,
  `active` int(11) NOT NULL,
  PRIMARY KEY (`channel_content_id`),
  KEY `channel_id` (`channel_id`),
  KEY `channel_platform_id` (`channel_platform_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=23 ;

--
-- Dumping data for table `channel_content`
--

INSERT INTO `channel_content` (`channel_content_id`, `channel_id`, `channel_platform_id`, `title`, `summary`, `image`, `dt_added`, `active`) VALUES
(1, 1, 1, 'Family fun at the beach', 'Beautiful', 'sample-photo-1.jpg', '2017-05-08 00:00:00', 1),
(2, 1, 1, 'Hi', 'Just a Hi', 'sample-photo-2.jpg', '2017-05-10 00:00:00', 1),
(3, 1, 1, 'Fun time', 'A fun time', 'sample-photo-3.jpg', '2017-05-15 00:00:00', 1),
(4, 11, 16, 'teachersdojo-logo-vertical.png', 'teachersdojo-logo-vertical.png', 'teachersdojo-logo-vertical.png', '2017-06-11 13:24:57', 0),
(5, 11, 16, 'teachersdojo-logo-horizontal.png', 'teachersdojo-logo-horizontal.png', 'teachersdojo-logo-horizontal.png', '2017-06-11 13:25:58', 0),
(6, 1, 7, 'teachersdojo-logo-vertical.png', 'teachersdojo-logo-vertical.png', 'teachersdojo-logo-vertical.png', '2017-06-11 13:32:45', 0),
(7, 1, 7, 'teachersdojo-logo-horizontal.png', 'teachersdojo-logo-horizontal.png', 'teachersdojo-logo-horizontal.png', '2017-06-11 13:32:46', 0),
(8, 2, 1, 'Beagle #1', 'Beautiful', 'beagle-1.jpg', '2017-05-08 00:00:00', 1),
(9, 2, 1, 'Beagle #2', 'Beautiful', 'beagle-2.jpg', '2017-05-08 00:00:00', 1),
(10, 2, 1, 'Beagle #3', 'Beautiful', 'beagle-3.jpg', '2017-05-08 00:00:00', 1),
(11, 11, 16, '10-teacher-tools-postpic 2.png', '10-teacher-tools-postpic 2.png', '10-teacher-tools-postpic 2.png', '2017-06-11 16:35:15', 0),
(12, 11, 16, 'download.jpg', 'download.jpg', 'download.jpg', '2017-06-12 01:07:56', 0),
(13, 2, 3, 'download.jpg', 'download.jpg', 'download.jpg', '2017-06-12 01:07:57', 0),
(14, 2, 3, 'IMAG0104.jpg', 'IMAG0104.jpg', 'IMAG0104.jpg', '2017-06-12 01:37:17', 0),
(15, 2, 3, 'IMAG0196-1.jpg', 'IMAG0196-1.jpg', 'IMAG0196-1.jpg', '2017-06-12 01:37:17', 0),
(16, 2, 3, 'IMAG0232.jpg', 'IMAG0232.jpg', 'IMAG0232.jpg', '2017-06-12 01:37:18', 0),
(17, 2, 3, 'IMG_1041.JPG', 'IMG_1041.JPG', 'IMG_1041.JPG', '2017-06-12 01:37:19', 0),
(18, 2, 3, 'IMG_1300.JPG', 'IMG_1300.JPG', 'IMG_1300.JPG', '2017-06-12 01:37:20', 0),
(19, 2, 3, 'IMG_1460.JPG', 'IMG_1460.JPG', 'IMG_1460.JPG', '2017-06-12 01:37:21', 0),
(20, 2, 3, 'IMG_1575.JPG', 'IMG_1575.JPG', 'IMG_1575.JPG', '2017-06-12 01:37:22', 0),
(21, 2, 3, 'IMG_1578.JPG', 'IMG_1578.JPG', 'IMG_1578.JPG', '2017-06-12 01:37:22', 0),
(22, 2, 3, 'IMG_1742.JPG', 'IMG_1742.JPG', 'IMG_1742.JPG', '2017-06-12 01:37:23', 0);

-- --------------------------------------------------------

--
-- Table structure for table `channel_platforms`
--

CREATE TABLE IF NOT EXISTS `channel_platforms` (
  `channel_platform_id` int(11) NOT NULL AUTO_INCREMENT,
  `channel_id` int(11) NOT NULL,
  `platform_id` int(11) NOT NULL,
  PRIMARY KEY (`channel_platform_id`),
  KEY `channel_id` (`channel_id`),
  KEY `platform_id` (`platform_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=24 ;

--
-- Dumping data for table `channel_platforms`
--

INSERT INTO `channel_platforms` (`channel_platform_id`, `channel_id`, `platform_id`) VALUES
(3, 2, 3),
(4, 3, 2),
(7, 1, 3),
(16, 11, 3),
(23, 1, 1);

-- --------------------------------------------------------

--
-- Table structure for table `channel_platform_data`
--

CREATE TABLE IF NOT EXISTS `channel_platform_data` (
  `channel_platform_data_id` int(11) NOT NULL AUTO_INCREMENT,
  `channel_platform_id` int(11) NOT NULL,
  `data_id` varchar(64) NOT NULL,
  `data_name` varchar(64) NOT NULL,
  PRIMARY KEY (`channel_platform_data_id`),
  KEY `channel_platform_id` (`channel_platform_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=27 ;

--
-- Dumping data for table `channel_platform_data`
--

INSERT INTO `channel_platform_data` (`channel_platform_data_id`, `channel_platform_id`, `data_id`, `data_name`) VALUES
(5, 12, 'id:9R_mOwEI4eEAAAAAAAAAIg', 'id:9R_mOwEI4eEAAAAAAAAAIg'),
(8, 16, 'id:9R_mOwEI4eEAAAAAAAAAIg', '/TEST FOLDER'),
(16, 16, 'id:9R_mOwEI4eEAAAAAAAAAIw', '/TEST FOLDER/Kids'),
(18, 7, 'id:9R_mOwEI4eEAAAAAAAAAJA', '/TEST FOLDER/Vacations'),
(26, 3, 'id:t43q--En9U8AAAAAAAEXqw', '/LOWY_RingFamily');

-- --------------------------------------------------------

--
-- Table structure for table `channel_platform_hashtags`
--

CREATE TABLE IF NOT EXISTS `channel_platform_hashtags` (
  `channel_platform_hasttag_id` int(11) NOT NULL AUTO_INCREMENT,
  `channel_platform_id` int(11) NOT NULL,
  `hashtag` varchar(32) NOT NULL,
  PRIMARY KEY (`channel_platform_hasttag_id`),
  KEY `channel_platform_id` (`channel_platform_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=14 ;

--
-- Dumping data for table `channel_platform_hashtags`
--

INSERT INTO `channel_platform_hashtags` (`channel_platform_hasttag_id`, `channel_platform_id`, `hashtag`) VALUES
(1, 1, '#elvis'),
(2, 1, '#sinatra'),
(7, 17, '#lowy'),
(10, 22, '#elvis'),
(11, 22, '#sinatra'),
(12, 23, '#elvis'),
(13, 23, '#sinatra');

-- --------------------------------------------------------

--
-- Table structure for table `clients`
--

CREATE TABLE IF NOT EXISTS `clients` (
  `client_id` int(11) NOT NULL AUTO_INCREMENT,
  `first_name` varchar(32) NOT NULL,
  `last_name` varchar(32) NOT NULL,
  `nickname` varchar(32) NOT NULL,
  `dob` datetime NOT NULL,
  `gender` char(1) NOT NULL,
  `room` varchar(12) NOT NULL,
  `device_id` varchar(64) NOT NULL,
  `chromecast_id` varchar(64) NOT NULL,
  `tv_id` varchar(64) NOT NULL,
  PRIMARY KEY (`client_id`),
  KEY `room` (`room`),
  KEY `device_id` (`device_id`),
  KEY `chromecast_id` (`chromecast_id`),
  KEY `tv_id` (`tv_id`),
  KEY `first_name` (`first_name`),
  KEY `last_name` (`last_name`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Dumping data for table `clients`
--

INSERT INTO `clients` (`client_id`, `first_name`, `last_name`, `nickname`, `dob`, `gender`, `room`, `device_id`, `chromecast_id`, `tv_id`) VALUES
(1, 'Jane', 'Doe', 'Janey', '1945-05-01 00:00:00', 'F', '12', 'ABC', 'DEF', '123');

-- --------------------------------------------------------

--
-- Table structure for table `client_users`
--

CREATE TABLE IF NOT EXISTS `client_users` (
  `client_user_id` int(11) NOT NULL AUTO_INCREMENT,
  `client_id` int(11) NOT NULL,
  `user_id` int(11) NOT NULL,
  `is_admin` int(11) NOT NULL,
  PRIMARY KEY (`client_user_id`),
  KEY `client_id` (`client_id`),
  KEY `user_id` (`user_id`),
  KEY `is_admin` (`is_admin`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Dumping data for table `client_users`
--

INSERT INTO `client_users` (`client_user_id`, `client_id`, `user_id`, `is_admin`) VALUES
(1, 1, 1, 1),
(2, 1, 2, 1);

-- --------------------------------------------------------

--
-- Table structure for table `messages`
--

CREATE TABLE IF NOT EXISTS `messages` (
  `message_id` int(11) NOT NULL AUTO_INCREMENT,
  `client_id` int(11) NOT NULL,
  `user_id` int(11) NOT NULL,
  `from_user` int(11) NOT NULL,
  `text` text NOT NULL,
  `audio_id` int(11) NOT NULL,
  `video_id` int(11) NOT NULL,
  `dt_sent` datetime NOT NULL,
  `dt_viewed` datetime NOT NULL,
  PRIMARY KEY (`message_id`),
  KEY `client_id` (`client_id`),
  KEY `user_id` (`user_id`),
  KEY `audio_id` (`audio_id`),
  KEY `video_id` (`video_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Dumping data for table `messages`
--

INSERT INTO `messages` (`message_id`, `client_id`, `user_id`, `from_user`, `text`, `audio_id`, `video_id`, `dt_sent`, `dt_viewed`) VALUES
(1, 1, 1, 1, 'Hi there Grandma', 0, 0, '2017-05-08 06:00:00', '0000-00-00 00:00:00'),
(2, 1, 1, 0, 'Hello sweetie', 0, 0, '2017-05-08 06:20:00', '0000-00-00 00:00:00');

-- --------------------------------------------------------

--
-- Table structure for table `message_audio`
--

CREATE TABLE IF NOT EXISTS `message_audio` (
  `message_audio_id` int(11) NOT NULL AUTO_INCREMENT,
  `audio_file` varchar(64) NOT NULL,
  `length` decimal(5,2) NOT NULL,
  PRIMARY KEY (`message_audio_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `message_video`
--

CREATE TABLE IF NOT EXISTS `message_video` (
  `message_video_id` int(11) NOT NULL AUTO_INCREMENT,
  `video_file` varchar(64) NOT NULL,
  `length` decimal(5,2) NOT NULL,
  PRIMARY KEY (`message_video_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `music`
--

CREATE TABLE IF NOT EXISTS `music` (
  `music_id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `description` mediumtext NOT NULL,
  `music_file` varchar(64) NOT NULL,
  PRIMARY KEY (`music_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `music`
--

INSERT INTO `music` (`music_id`, `name`, `description`, `music_file`) VALUES
(1, 'Song #1', 'This is song #1', 'song1.mp4'),
(2, 'Song #2', 'This is song #2', 'song2.mp4'),
(3, 'Song #3', 'This is song #3', 'song3.mp4');

-- --------------------------------------------------------

--
-- Table structure for table `platforms`
--

CREATE TABLE IF NOT EXISTS `platforms` (
  `platform_id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `icon` varchar(32) NOT NULL,
  `color` varchar(7) NOT NULL,
  `share_title` varchar(64) NOT NULL,
  `share_instructions` mediumtext NOT NULL,
  `app_id` varchar(128) NOT NULL,
  `app_secret` varchar(128) NOT NULL,
  `app_scope` varchar(64) NOT NULL,
  PRIMARY KEY (`platform_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=9 ;

--
-- Dumping data for table `platforms`
--

INSERT INTO `platforms` (`platform_id`, `name`, `icon`, `color`, `share_title`, `share_instructions`, `app_id`, `app_secret`, `app_scope`) VALUES
(1, 'Facebook', 'facebook', '#3b5998', 'How to share on Facebook:', 'To add an image or video to this channel include the special hastags <span class="lowytag">#LOWY</span> and <span class="lowytag">#LOWY[CHANNEL-NAME]</span> in your post and the content of the post will automatically be added to this channel.\r\n', '1546675118699904', '899b0a1f953468a281e296dc93b518b7', 'email,user_friends'),
(2, 'Pinterest', 'pinterest', '#C92228', 'How to share on Pinterest:', 'To add an image or video to this channel include the special hastags <span class="lowytag">#LOWY</span> and <span class="lowytag">#LOWY[CHANNEL-NAME]</span> in your pin and the content of the pin will automatically be added to this channel.', '4899703348545995209', 'e2cd26c796eb1e834fd15d28645e5f2d160ce77af37d7b701a464b70d4eea773', 'read_public'),
(3, 'Dropbox', 'dropbox', '#007ee5', 'How to share from Dropbox', 'To add an image or video from a folder to this channel simply check the folder name below and any new content added to the folder will automatically be added to this channel.', 'cz5m89vemg7z3tf', '7eli5x63ou04can', ''),
(4, 'Twitter', 'twitter', '#00aced', 'How to share on Twitter:', 'To add an image or video to this channel include the special hastags <span class="lowytag">#LOWY</span> and <span class="lowytag">#LOWY[CHANNEL-NAME]</span> in your tweet and the content of the tweet will automatically be added to this channel.', 'PY4npBByzgJ6ZzxlyPQ573Kkj', '3ov8qUBpXZ32yJjgDqHrQCANb7YoKpTcfHQkqHxIHW4OjXV4gP', 'read'),
(5, 'Instagram', 'instagram', '#fb3958', 'How to share on Instagram:', 'To add an image or video to this channel include the special hastags <span class="lowytag">#LOWY</span> and <span class="lowytag">#LOWY[CHANNEL-NAME]</span> in your post and the content of the post will automatically be added to this channel.', '7566e1c51aa14da58b019b0f9e989881', '22099f5cb23b4241861e0dc7debe86f2', 'basic'),
(6, 'YouTube', 'youtube', '#b31217', 'How to share on YouTube:', 'To add a video to this channel include the special hastags <span class="lowytag">#LOWY</span> and <span class="lowytag">#LOWY[CHANNEL-NAME]</span> in your descriptiuon and the video will automatically be added to this channel.', '', '', ''),
(7, 'Vimeo', 'vimeo', '#1ab7ea', 'How to share on Vimeo:', 'To add a video to this channel include the special hastags <span class="lowytag">#LOWY</span> and <span class="lowytag">#LOWY[CHANNEL-NAME]</span> in your descriptiuon and the video will automatically be added to this channel.', '', '', ''),
(8, 'Google Phots', 'google', '#c7c7c7', 'How to share on Google Photos:', 'To add an image to this channel include the special hastags <span class="lowytag">#LOWY</span> and <span class="lowytag">#LOWY[CHANNEL-NAME]</span> in your descriptiuon and the image will automatically be added to this channel.', '', '', '');

-- --------------------------------------------------------

--
-- Table structure for table `social_media_sessions`
--

CREATE TABLE IF NOT EXISTS `social_media_sessions` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `session` char(32) NOT NULL DEFAULT '',
  `state` char(32) NOT NULL DEFAULT '',
  `access_token` mediumtext NOT NULL,
  `expiry` datetime DEFAULT NULL,
  `type` char(12) NOT NULL DEFAULT '',
  `server` char(12) NOT NULL DEFAULT '',
  `creation` datetime NOT NULL DEFAULT '2000-01-01 00:00:00',
  `access_token_secret` mediumtext NOT NULL,
  `authorized` char(1) DEFAULT NULL,
  `user` int(10) unsigned NOT NULL DEFAULT '0',
  `refresh_token` mediumtext NOT NULL,
  `access_token_response` mediumtext,
  `page_id` varchar(64) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `social_oauth_session_index` (`session`,`server`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=71 ;

--
-- Dumping data for table `social_media_sessions`
--

INSERT INTO `social_media_sessions` (`id`, `session`, `state`, `access_token`, `expiry`, `type`, `server`, `creation`, `access_token_secret`, `authorized`, `user`, `refresh_token`, `access_token_response`, `page_id`) VALUES
(46, '1', '7484a46c2045ba8bd6498870742a27e6', 'Aep21JGtyYERBryEyq1TUT886NLQFL1F8llJEXFD_z508YA_RwAAAAA', NULL, 'bearer', 'Pinterest', '2017-05-10 14:45:51', '', 'Y', 1, '', 'null', ''),
(47, '1', 'd0d2326385000705559ad848cea4c82e', 'EAAVZBsV0IdYABANGyfzGN07hpefDS3hEbgf6kZBZCbE4XU3YbZBckV7ZAFmfWp9tIc7HHvtAHa2SHp5ZA3jeyOnlyjj05pjCAGA0RLpTz9kEUzFioHon6p2TchPVhWSfFPM7svSSzOcwSwQGM3mMvCGGbwzoW8bvkZD', '2017-07-09 15:07:52', 'bearer', 'Facebook', '2017-05-10 15:07:52', '', 'Y', 1, '', 'null', ''),
(68, '1', 'f85d4879e0642c95b9675d27a7dd04d5', '8HhXXQAAAAAA0kOgAAABXRX355g', NULL, '', 'Twitter', '2017-07-06 03:35:54', 'Crgz6mvb1xKM8WricTlQIiIWcWunbARN', 'N', 0, '', 'null', ''),
(70, '1', '4f3bfc644ebc9a740b9b731ff5471bcf', 'fCbuKjOqKpgAAAAAAACYrbj-CmiPUMgi2p63RknyIVr5RigrCI3znr3FvVIX_Gsj', NULL, 'bearer', 'Dropbox', '2017-07-06 05:21:40', '', 'Y', 1, '', 'null', '');

-- --------------------------------------------------------

--
-- Table structure for table `themes`
--

CREATE TABLE IF NOT EXISTS `themes` (
  `theme_id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `description` mediumtext NOT NULL,
  `cover_file` varchar(32) NOT NULL,
  PRIMARY KEY (`theme_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `themes`
--

INSERT INTO `themes` (`theme_id`, `name`, `description`, `cover_file`) VALUES
(1, 'Pink', 'Pink theme', 'frame-bg-1.jpg'),
(2, 'Green', 'Green theme', 'frame-bg-2.jpg'),
(3, 'Purple', 'Purple theme', 'frame-bg-3.jpg');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `user_id` int(11) NOT NULL AUTO_INCREMENT,
  `is_admin` int(11) NOT NULL,
  `first_name` varchar(32) NOT NULL,
  `last_name` varchar(32) NOT NULL,
  `nickname` varchar(32) NOT NULL,
  `email` varchar(64) NOT NULL,
  `address_1` varchar(32) NOT NULL,
  `address_2` varchar(32) NOT NULL,
  `city` varchar(32) NOT NULL,
  `state` varchar(2) NOT NULL,
  `zip` varchar(10) NOT NULL,
  `phone` varchar(15) NOT NULL,
  `gender` char(1) NOT NULL,
  `dob` date NOT NULL,
  `avatar` varchar(64) NOT NULL,
  `verify_code` varchar(64) NOT NULL,
  `reset_code` varchar(64) NOT NULL,
  `dt_added` datetime NOT NULL,
  `dt_updated` datetime NOT NULL,
  `dt_closed` datetime NOT NULL,
  PRIMARY KEY (`user_id`),
  KEY `is_admin` (`is_admin`),
  FULLTEXT KEY `verify_code` (`verify_code`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`user_id`, `is_admin`, `first_name`, `last_name`, `nickname`, `email`, `address_1`, `address_2`, `city`, `state`, `zip`, `phone`, `gender`, `dob`, `avatar`, `verify_code`, `reset_code`, `dt_added`, `dt_updated`, `dt_closed`) VALUES
(1, 1, 'Steve', 'Esemplare', 'Steve', 'steve@loveourway.com', '66 Streambank Drive', '', 'Freehold', 'NJ', '07728', '732-667-3532', 'M', '1965-12-21', '2897dbc.jpg', '', '', '2017-05-07 00:00:00', '2017-05-07 00:00:00', '0000-00-00 00:00:00'),
(2, 0, 'Ryan', 'Ring', 'Ryan', 'ryan@loveourway.com', '123 Main Street', '', 'Los Angeles', 'CA', '90001', '555-555-1212', 'M', '1970-01-01', '139bbdd.jpg', '', '', '2017-05-07 00:00:00', '2017-05-07 00:00:00', '0000-00-00 00:00:00');

-- --------------------------------------------------------

--
-- Table structure for table `video_calls`
--

CREATE TABLE IF NOT EXISTS `video_calls` (
  `video_call_id` int(11) NOT NULL AUTO_INCREMENT,
  `client_id` int(11) NOT NULL,
  `client_initiated` int(11) NOT NULL,
  `video_file` varchar(64) NOT NULL,
  `length` decimal(5,2) NOT NULL,
  `dt_started` datetime NOT NULL,
  PRIMARY KEY (`video_call_id`),
  KEY `client_id` (`client_id`),
  KEY `length` (`length`),
  KEY `dt_started` (`dt_started`),
  KEY `video_file` (`video_file`),
  KEY `client_initiated` (`client_initiated`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `video_call_users`
--

CREATE TABLE IF NOT EXISTS `video_call_users` (
  `video_call_user_id` int(11) NOT NULL AUTO_INCREMENT,
  `video_call_id` int(11) NOT NULL,
  `client_id` int(11) NOT NULL,
  `user_id` int(11) NOT NULL,
  `dt_joined` datetime NOT NULL,
  `dt_left` datetime NOT NULL,
  PRIMARY KEY (`video_call_user_id`),
  KEY `video_call_id` (`video_call_id`),
  KEY `client_id` (`client_id`),
  KEY `user_id` (`user_id`),
  KEY `dt_joined` (`dt_joined`),
  KEY `dt_left` (`dt_left`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
