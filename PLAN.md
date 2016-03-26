# Development Plan

## Modules

### configuration

Uses `libconfig` to read a `.cfg` file with configuration settings for the hardware and deployment.

#### functionality

* read parameters in `beaglebat.cfg` into (what type?) of object(s). This object(s) will contain the setting used in downstream functions.
	* hardware settings
		* device - how will this be identified?
		* rate - the sampling rate of the device
		* channels - number of channels of the device
		* buffer frames - number of frames to read from the buffer
	* data settings
		* media_loc - location for output (e.g. an SD card at /media/store)
		* file_names - (future) provide options for 
	* deployment settings
		* project_id
		* deployment_id
		* trigger_freq
		* lag_time
		* type - "point" or "mobile"
		* schedule - "none" or "user" (if 'none' record does not stop until told by user)
		* if schedule == 'user' then a schedule need to be set
			* how to set schedule? start/end date and times or daily schedule?
* check if /deployment_id directory has been created as well as /log and /files subdirectories; if not, create. If these directories are nonempty, give warning.
* set hardware parameters for device
* return errors and/or warnings if any of the above are not set, out of reasonable ranges, or will not work for the hardware
* give message that settings successfully configured
* write configuration success to deployment log with 
* (future) write to and update `.cfg` file from command line

### capture/detect/record

* Uses `alsa` to capture and record data from microphone
* converts raw data to frequency domain. If max frequency > trigger_freq then trigger recording. Record until max freq < trigger_freq for lag_time
* write .wav files to /files directory
* write info to log file : date, time, filename, deployment_id, duration, gps coords (if using mobile type and gps installed)

### power

* monitors and manages power supply

### gps

* read coords from gps device
* make this data available to other modules