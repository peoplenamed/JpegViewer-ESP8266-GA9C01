# Link or move this python file to klipper/klippy/extras/
# Add config section described below to printer.cfg
class PyxelKlipperPluginHelper:
    def __init__(self, config):
        self.printer = config.get_printer()
        self.printer.register_event_handler("klippy:connect", self.handle_connect)

        # Grab color values from config file
        self.background_color = config.getlist("background_color")
        self.foreground_color = config.getlist("foreground_color")
        self.serial_port = config.getlist("serial_port") | "/dev/ttyUSB0"
        self.baud_rate = config.getlist(baud_rate) | 115200
        self.arduino = serial.Serial(port=self.serial_port,  baudrate=self.baud_rate, timeout=.1)

        # example config file section in printer.cfg:
        # [pyxel_klipper_plugin]
        #   background_color: 34784
        #   foreground_color: 60445
        #   baud_rate: 115200
        #   serial_port: "/dev/ttyUSB0"

        # Initialize Animation Variables
        self.POPEYEFACE_ANIMATION = "<0>"
        self.FANGFACE_ANIMATION = "<1>"
        self.GRUMPYFACE_ANIMATION = "<2>"
        self.WINKFACE_ANIMATION = "<3>"
        self.ANGRYFACE_ANIMATION = "<4>"
        self.NORMAL_ANIMATION = "<6>"
        self.LOADINGFACE_ANIMATION = "<8>"
        self.HAPPYFACE_ANIMATION = "<9>"
        self.PUKERAINBOWFACE_ANIMATION = "<10>"
        self.ANGRYFACE_ANIMATION = "<11>"
        self.SLEEPFACE_ANIMATION = "<12>"
        self.GRUMPYFACE_ANIMATION = "<13>"
        self.WINKFACE_ANIMATION = "<14>"
        self.SATISFIEDFACE_ANIMATION = "<15>"
        self.POPEYEFACE_ANIMATION = "<16>"
        self.FANGFACE_ANIMATION = "<17>"
        self.CIRCLEWIPE = "<25>"
        self.CIRCLEWIPE = "<26>"
        self.TRIANGLEWIPE = "<27>"
        self.TRIANGLEWIPE = "<28>"
        self.CIRCLEWIPE = "<29>"
        self.DIMONDEYES = "<75>"
        self.OCTOCAT = "<76>"
        self.CALVINANDHOBBES = "<77>"

    def handle_connect(self):
        # Unsure what this does. I think it initializes the plugin
       k = self.printer.lookup_object('toolhead').get_kinematics()

    # write main part of the functionality below

    # E.g. move the toolhead from point A to point B
    def play_animation(self, selected_animation):
        arduino.write(bytes(selected_animation,  'utf-8'))


class PyxelKlipperPlugin:
    def __init__(self, config):
        self.printer = config.get_printer()
        self.pyxel_klipper_plugin_helper = PyxelKlipperPluginHelper(config)
        gcode = self.printer.lookup_object('gcode')

        # make your gcode recognisable
        gcode.register_command("PYXEL_GCODE_MACRO", self.cmd_PYXEL_GCODE_MACRO, self.cmd_PYXEL_GCODE_MACRO_help)

    # These are the filament properties in GCODE
    # filament_colour
    # filament_settings_id
    # filament_type
    cmd_PYXEL_GCODE_MACRO_help = "This will overwrite the pause command with a callback to update the Pyxel display"
    def cmd_PYXEL_GCODE_MACRO(self, gcmd):
        self.pyxel_klipper_plugin_helper.play_animation(self.ANGRY_FACE_ANIMATION)
    
def load_config(config):
    return PyxelKlipperPlugin(config)