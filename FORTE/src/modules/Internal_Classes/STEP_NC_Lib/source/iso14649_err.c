/************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute
  is not subject to copyright in the United States.  Recipients of this
  software assume all responsibility associated with its operation,
  modification, maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
************************************************************************/

char * _iso14649_errors[] = {
/*   0 */ "No error",
/*   1 */ "No error",
/*   2 */ "No error",
/*   3 */ "No error",
/*   4 */ "Action flag value must have known meaning",
/*   5 */ "A file must not be already open",
/*   6 */ "Allowance bottom must not be negative",
/*   7 */ "Allowance side must not be negative",
/*   8 */ "Axial cutting depth must not be negative",
/*   9 */ "Axis length of placement must not be tiny",
/*  10 */ "Axis of placement must be perpendicular to ref direction",
/*  11 */ "Bottom dwell time must not be negative",
/*  12 */ "Bug in entering pocket",
/*  13 */ "Can handle only closed pocket for finish mill bottom and side",
/*  14 */ "Can handle only closed pocket for rough mill bottom and side",
/*  15 */ "Can handle only connect and trajectorypath path types",
/*  16 */ "Can handle only connect or trajectorypath toolpath type",
/*  17 */ "Can handle only contour parallel milling strategy",
/*  18 */ "Can handle only course of travel parallel to feature y axis",
/*  19 */ "Can handle only course of travel parallel to positive feature y axis",
/*  20 */ "Can handle only feedstop and cutter location trajectory",
/*  21 */ "Can handle only line and circle and helix in a trimmed curve",
/*  22 */ "Can handle only plunge approach",
/*  23 */ "Can handle only plunge toolaxis approach for plane milling",
/*  24 */ "Can handle only plunge toolaxis retract",
/*  25 */ "Can handle only plunge toolaxis retract for plane milling",
/*  26 */ "Can handle only plus minus value tolerance",
/*  27 */ "Can handle only straight line move at start of rapid",
/*  28 */ "Can handle only trajectorypath path type for circle",
/*  29 */ "Can handle only trajectorypath path type for helix",
/*  30 */ "Can handle only unidirectional and bidirectional plane milling",
/*  31 */ "Cannot execute touch probing",
/*  32 */ "Cannot follow bounded curve backward",
/*  33 */ "Cannot handle adaptive control",
/*  34 */ "Cannot handle axis clamping",
/*  35 */ "Cannot handle backboring",
/*  36 */ "Cannot handle boring",
/*  37 */ "Cannot handle bosses in pocket",
/*  38 */ "Cannot handle boss on planar face",
/*  39 */ "Cannot handle compound feature",
/*  40 */ "Cannot handle coolant pressure",
/*  41 */ "Cannot handle freeform machining strategy",
/*  42 */ "Cannot handle index pallet",
/*  43 */ "Cannot handle index table",
/*  44 */ "Cannot handle non straightline connection strategy",
/*  45 */ "Cannot handle other functions",
/*  46 */ "Cannot handle outside in cutting",
/*  47 */ "Cannot handle placement of course of travel",
/*  48 */ "Cannot handle placement of removal boundary",
/*  49 */ "Cannot handle pocket with fillet at bottom",
/*  50 */ "Cannot handle process model",
/*  51 */ "Cannot handle profile placement",
/*  52 */ "Cannot handle program structure",
/*  53 */ "Cannot handle rapid movement without toolpath",
/*  54 */ "Cannot handle replicate feature",
/*  55 */ "Cannot handle set mark",
/*  56 */ "Cannot handle side finish milling",
/*  57 */ "Cannot handle side rough milling",
/*  58 */ "Cannot handle sloped pocket",
/*  59 */ "Cannot handle speed in toolpath",
/*  60 */ "Cannot handle speed profile",
/*  61 */ "Cannot handle strategy for multistep drilling",
/*  62 */ "Cannot handle tapping",
/*  63 */ "Cannot handle this many lines of code",
/*  64 */ "Cannot handle thread drilling",
/*  65 */ "Cannot handle through pressure",
/*  66 */ "Cannot handle through spindle coolant",
/*  67 */ "Cannot handle toolaxis",
/*  68 */ "Cannot handle tool direction",
/*  69 */ "Cannot handle transition feature",
/*  70 */ "Cannot handle wait for mark",
/*  71 */ "Cannot hold milling tolerance tighter than one hundredth mm",
/*  72 */ "Cannot machine a region",
/*  73 */ "Cannot perform operation on feature",
/*  74 */ "Center drilling cutting depth must not be greater than depth",
/*  75 */ "Center drilling depth must not exceed center drill flute length",
/*  76 */ "Center drilling must have cutting depth",
/*  77 */ "Center drilling must not have overcut length",
/*  78 */ "Center drilling must not have strategy",
/*  79 */ "Circle z axis must be parallel to machine z axis",
/*  80 */ "Command code type must be motion speed or feed",
/*  81 */ "Composite curve must be continuous",
/*  82 */ "Composite curve segment must be a bounded curve",
/*  83 */ "Coolant must be true or false",
/*  84 */ "Counterbore depth must equal cutting depth",
/*  85 */ "Counterbore hole elements must not be null",
/*  86 */ "Counterbore hole must have exactly two elements",
/*  87 */ "Counterbore hole subholes must not be in same place",
/*  88 */ "Counterboring must not have overcut length",
/*  89 */ "Counterboring must not have strategy",
/*  90 */ "Countersink cutting portion must reach hole bottom",
/*  91 */ "Countersink depth must match hole depth",
/*  92 */ "Countersinking must not have overcut length",
/*  93 */ "Countersinking must not have strategy",
/*  94 */ "Countersunk hole elements must not be null",
/*  95 */ "Countersunk hole must have exactly two elements",
/*  96 */ "Countersunk hole subholes must not be in same place",
/*  97 */ "Course of travel direction must not be null",
/*  98 */ "Course of travel distance must not be null",
/*  99 */ "Cutting depth must be positive",
/* 100 */ "Cutting edge length must be given",
/* 101 */ "Cutting edge length must be positive",
/* 102 */ "Default placement axis must be zero zero one",
/* 103 */ "Default placement origin must be at zero zero zero",
/* 104 */ "Default placement ref direction must be one zero zero",
/* 105 */ "Dimension must not be null",
/* 106 */ "Direction must not be null",
/* 107 */ "Direction ratio must be given",
/* 108 */ "Direction ratios must not all be zero",
/* 109 */ "Direction ratios must not be null",
/* 110 */ "Disable must be true or false",
/* 111 */ "Dwell time must not be negative",
/* 112 */ "Edge radius must be given",
/* 113 */ "Edge radius must be zero or not given",
/* 114 */ "Edge radius must not be negative",
/* 115 */ "End depth must be greater than start depth",
/* 116 */ "End depth must be less than cutting depth",
/* 117 */ "Endmill diameter must equal hole diameter",
/* 118 */ "Executable must not be null",
/* 119 */ "Executable type must be defined type",
/* 120 */ "External queue must be empty",
/* 121 */ "Feature for plane milling must be planar face",
/* 122 */ "Feature must not be null",
/* 123 */ "Feature z axis must be parallel to machine z axis",
/* 124 */ "Feed direction must parallel x or y axis of planar face",
/* 125 */ "Feed on retract must not be negative or tiny",
/* 126 */ "Feedrate must be given for rapid",
/* 127 */ "File must have exactly one project",
/* 128 */ "File must have exactly one setup",
/* 129 */ "File must have exactly one workpiece",
/* 130 */ "File must have exactly one workpiece setup",
/* 131 */ "File name must not be too long",
/* 132 */ "Finish milling both can handle only plunge strategy",
/* 133 */ "Finish milling both must not have overcut length",
/* 134 */ "First element of counterbore hole must be a round hole",
/* 135 */ "First element of counterbore hole must not be null",
/* 136 */ "First element of countersunk hole must be a round hole",
/* 137 */ "First element of countersunk hole must not be null",
/* 138 */ "First subhole of counterbore hole must be vertical",
/* 139 */ "First subhole of countersunk hole must be vertical",
/* 140 */ "Freeform milling can handle only plunge strategy",
/* 141 */ "Freeform milling must have a toolpath",
/* 142 */ "Helix must fit in pocket",
/* 143 */ "Helix pitch must not be zero",
/* 144 */ "Helix z axis must be parallel to machine z axis",
/* 145 */ "Hole diameter must not exceed countersink diameter",
/* 146 */ "Hole must not be deeper than endmill is long",
/* 147 */ "Hole must not be deeper than flute length",
/* 148 */ "Input file must be readable",
/* 149 */ "Last command code type must be feed or traverse",
/* 150 */ "Length of planar face must be positive",
/* 151 */ "Length units must be millimeters",
/* 152 */ "Machine functions must be milling machine functions",
/* 153 */ "Machining operation type must be defined type",
/* 154 */ "Machining tool must be a cutting tool",
/* 155 */ "Main workplan must not be null",
/* 156 */ "Manufacturing feature type must be defined type",
/* 157 */ "Must have feedrate or feedrate per tooth",
/* 158 */ "Must have spindle speed or surface speed",
/* 159 */ "Must not cut with left hand tool turning clockwise",
/* 160 */ "Must not cut with right hand tool turning counterclockwise",
/* 161 */ "Must not have both cutting depth and overcut",
/* 162 */ "Must not have both feedrate and feedrate per tooth",
/* 163 */ "Must not have both spindle speed and surface speed",
/* 164 */ "Must not use cutspeed in rapid",
/* 165 */ "Must not use feedrate per tooth in rapid",
/* 166 */ "Must use plunge toolaxis to approach when pocket same size as tool",
/* 167 */ "Must use plunge toolaxis to retract when pocket same size as tool",
/* 168 */ "Number of direction ratios must be three",
/* 169 */ "Number of teeth must be given",
/* 170 */ "Number of teeth must be positive",
/* 171 */ "Operation must belong to feature",
/* 172 */ "Operation must not be null",
/* 173 */ "Other functions must not be null",
/* 174 */ "Overcut for bidirectional must be at least half a tool diameter",
/* 175 */ "Overcut for unidirectional must be at least 1point2 tool diameters",
/* 176 */ "Overcut must be positive",
/* 177 */ "Overlap must be between zero and one",
/* 178 */ "Peck amount must be positive",
/* 179 */ "Placement axis coordinate values must all be given",
/* 180 */ "Placement axis must not be null",
/* 181 */ "Placement location must not be null",
/* 182 */ "Placement must not be null",
/* 183 */ "Placement origin coordinate values must all be given",
/* 184 */ "Placement origin must have three coords",
/* 185 */ "Placement ref direction coordinate values must all be given",
/* 186 */ "Placement ref direction must not be null",
/* 187 */ "Planar face course of travel must not be null",
/* 188 */ "Planar face its boss must not be null",
/* 189 */ "Planar face removal boundary must not be null",
/* 190 */ "Plane depth must be below plane top",
/* 191 */ "Plane must be horizontal",
/* 192 */ "Plunge strategy type must be defined type",
/* 193 */ "Pocket boss set must not be null",
/* 194 */ "Pocket boundary must not be null",
/* 195 */ "Pocket corner radius must be positive",
/* 196 */ "Pocket corner radius must not be null",
/* 197 */ "Pocket corner radius must not exceed half pocket width",
/* 198 */ "Pocket depth must be below pocket top",
/* 199 */ "Pocket depth must be positive",
/* 200 */ "Pocket length must be positive",
/* 201 */ "Pocket length tolerance must not be null",
/* 202 */ "Pocket must have rectangular closed profile",
/* 203 */ "Pocket must not be narrower than tool",
/* 204 */ "Pocket profile length must not be null",
/* 205 */ "Pocket profile width must not be null",
/* 206 */ "Pocket width must be positive",
/* 207 */ "Pocket width must exceed tool diameter for plunge helix",
/* 208 */ "Pocket width must not exceed length",
/* 209 */ "Pocket width tolerance must not be null",
/* 210 */ "Polyline must have at least two points",
/* 211 */ "Previous diameter must not differ from lower hole diameter",
/* 212 */ "Project main workplan setup must be file setup",
/* 213 */ "Project must have exactly one workpiece",
/* 214 */ "Project workpiece must be file workpiece",
/* 215 */ "Radial cutting depth must not be negative",
/* 216 */ "Ramp must fit in pocket",
/* 217 */ "Rapid must start at current location",
/* 218 */ "Reaming must not have depth of testcut",
/* 219 */ "Reaming must not have waiting position",
/* 220 */ "Ref direction length of placement must not be tiny",
/* 221 */ "Removal boundary profile length must not be null",
/* 222 */ "Required tool must be in tool table",
/* 223 */ "Retract must not go above security plane",
/* 224 */ "Retract plane must not be negative",
/* 225 */ "Rough milling both can handle only plunge strategy",
/* 226 */ "Rough milling both must not have overcut length",
/* 227 */ "Second element of counterbore hole must be a round hole",
/* 228 */ "Second element of counterbore hole must not be null",
/* 229 */ "Second element of countersunk hole must be a round hole",
/* 230 */ "Second element of countersunk hole must not be null",
/* 231 */ "Second subhole of counterbore hole must be vertical",
/* 232 */ "Second subhole of countersunk hole must be vertical",
/* 233 */ "Secplane must be a plane",
/* 234 */ "Setup workpiece setup must be file workpiece setup",
/* 235 */ "Spindle speed must be given in technology for rapid",
/* 236 */ "Spindle stop at bottom must be true or false",
/* 237 */ "Start depth must be less than cutting depth",
/* 238 */ "Step dwell time must not be negative",
/* 239 */ "Subholes of counterbore hole must be coaxial",
/* 240 */ "Subholes of countersunk hole must be coaxial",
/* 241 */ "Surface must be a plane",
/* 242 */ "Surface must not be null",
/* 243 */ "Synch must be true or false",
/* 244 */ "Technology must be milling technology",
/* 245 */ "The setup must have exactly one workpiece setup",
/* 246 */ "The tool must be null in unload tool",
/* 247 */ "Tolerance limits must not be negative",
/* 248 */ "Tool body for machining must be a milling tool body",
/* 249 */ "Tool body must be a center drill",
/* 250 */ "Tool body must be a countersink",
/* 251 */ "Tool body must be an endmill",
/* 252 */ "Tool body must be an endmill or a facemill",
/* 253 */ "Tool body must be a reamer",
/* 254 */ "Tool body must be a twist drill",
/* 255 */ "Tool body must not be null",
/* 256 */ "Tool circumference angle must be given",
/* 257 */ "Tool circumference angle must be less than ninety degrees",
/* 258 */ "Tool circumference angle must be zero or not given",
/* 259 */ "Tool circumference angle must not be negative",
/* 260 */ "Tool diameter must be positive",
/* 261 */ "Tool diameter must not be zero",
/* 262 */ "Tool diameters must be same for same tool",
/* 263 */ "Tool for machining must be a cutting tool",
/* 264 */ "Tool for machining must have exactly one component",
/* 265 */ "Tool for plane milling must be endmill or facemill",
/* 266 */ "Tool handedness must be given",
/* 267 */ "Tool max must not exceed canon tool max",
/* 268 */ "Tool must be able to retract to setup security plane",
/* 269 */ "Tool must be a cutting tool",
/* 270 */ "Tool must be in toolchanger",
/* 271 */ "Tool must fit in corners of pocket",
/* 272 */ "Tool must not be null",
/* 273 */ "Tool must not be too long to retract to setup security plane",
/* 274 */ "Tool orientation must be null",
/* 275 */ "Toolpath list must not be empty",
/* 276 */ "Toolpath list must not be null",
/* 277 */ "Tool taper must equal hole taper",
/* 278 */ "Tool top angle must be given",
/* 279 */ "Tool top angle must be less than ninety degrees",
/* 280 */ "Tool top angle must be zero or not given",
/* 281 */ "Tool top angle must not be negative",
/* 282 */ "Trajectory must not have gap",
/* 283 */ "Trim element must be a cartesian point",
/* 284 */ "Trim list must have one element",
/* 285 */ "Upper and lower holes of counterbore hole must mate vertically",
/* 286 */ "Upper and lower holes of countersunk hole must mate in diameter",
/* 287 */ "Upper and lower holes of countersunk hole must mate vertically",
/* 288 */ "Upper hole diameter of counterbore hole must be greater than lower",
/* 289 */ "Upper hole diameter of countersunk hole must be greater than lower",
/* 290 */ "Upper hole of counterbore hole must not taper",
/* 291 */ "Upper hole of countersunk hole must taper",
/* 292 */ "Upper hole taper must be diameter taper or angle taper",
/* 293 */ "Width of planar face must be positive",
/* 294 */ "Workingstep type must be defined type",
/* 295 */ "Workpiece setup workpiece must be file workpiece",
/* 296 */ "Z axis must be vertical",
/* 297 */ "Zigzag must fit in pocket",
"The End"};
