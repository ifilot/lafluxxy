/**************************************************************************
 *                                                                        *
 *   Author: Ivo Filot <i.a.w.filot@tue.nl>                               *
 *                                                                        *
 *   LaFluxxy is free software:                                           *
 *   you can redistribute it and/or modify it under the terms of the      *
 *   GNU General Public License as published by the Free Software         *
 *   Foundation, either version 3 of the License, or (at your option)     *
 *   any later version.                                                   *
 *                                                                        *
 *   LaFluxxy is distributed in the hope that it will be useful,          *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty          *
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.              *
 *   See the GNU General Public License for more details.                 *
 *                                                                        *
 *   You should have received a copy of the GNU General Public License    *
 *   along with this program.  If not, see http://www.gnu.org/licenses/.  *
 *                                                                        *
 **************************************************************************/

#pragma once

/*
 * The scheme has been obtained using this link:
 * https://github.com/BIDS/colormap/blob/master/colormaps.py
 */

#include <vector>

static const std::vector<float> color_scheme_spectral =
               {0.619608f, 0.003922f, 0.258824f,
                0.628066f, 0.013303f, 0.260823f,
                0.636524f, 0.022684f, 0.262822f,
                0.644983f, 0.032065f, 0.264821f,
                0.653441f, 0.041446f, 0.266820f,
                0.661899f, 0.050827f, 0.268820f,
                0.670358f, 0.060208f, 0.270819f,
                0.678816f, 0.069589f, 0.272818f,
                0.687274f, 0.078970f, 0.274817f,
                0.695732f, 0.088351f, 0.276817f,
                0.704191f, 0.097732f, 0.278816f,
                0.712649f, 0.107113f, 0.280815f,
                0.721107f, 0.116494f, 0.282814f,
                0.729566f, 0.125875f, 0.284814f,
                0.738024f, 0.135256f, 0.286813f,
                0.746482f, 0.144637f, 0.288812f,
                0.754940f, 0.154018f, 0.290811f,
                0.763399f, 0.163399f, 0.292810f,
                0.771857f, 0.172780f, 0.294810f,
                0.780315f, 0.182161f, 0.296809f,
                0.788774f, 0.191542f, 0.298808f,
                0.797232f, 0.200923f, 0.300807f,
                0.805690f, 0.210304f, 0.302807f,
                0.814148f, 0.219685f, 0.304806f,
                0.822607f, 0.229066f, 0.306805f,
                0.831065f, 0.238447f, 0.308804f,
                0.837678f, 0.246751f, 0.308881f,
                0.842445f, 0.253979f, 0.307036f,
                0.847213f, 0.261207f, 0.305190f,
                0.851980f, 0.268435f, 0.303345f,
                0.856747f, 0.275663f, 0.301499f,
                0.861515f, 0.282891f, 0.299654f,
                0.866282f, 0.290119f, 0.297809f,
                0.871050f, 0.297347f, 0.295963f,
                0.875817f, 0.304575f, 0.294118f,
                0.880584f, 0.311803f, 0.292272f,
                0.885352f, 0.319031f, 0.290427f,
                0.890119f, 0.326259f, 0.288581f,
                0.894887f, 0.333487f, 0.286736f,
                0.899654f, 0.340715f, 0.284890f,
                0.904421f, 0.347943f, 0.283045f,
                0.909189f, 0.355171f, 0.281200f,
                0.913956f, 0.362399f, 0.279354f,
                0.918724f, 0.369627f, 0.277509f,
                0.923491f, 0.376855f, 0.275663f,
                0.928258f, 0.384083f, 0.273818f,
                0.933026f, 0.391311f, 0.271972f,
                0.937793f, 0.398539f, 0.270127f,
                0.942561f, 0.405767f, 0.268281f,
                0.947328f, 0.412995f, 0.266436f,
                0.952095f, 0.420223f, 0.264591f,
                0.956863f, 0.427451f, 0.262745f,
                0.958247f, 0.437447f, 0.267359f,
                0.959631f, 0.447443f, 0.271972f,
                0.961015f, 0.457439f, 0.276586f,
                0.962399f, 0.467436f, 0.281200f,
                0.963783f, 0.477432f, 0.285813f,
                0.965167f, 0.487428f, 0.290427f,
                0.966551f, 0.497424f, 0.295040f,
                0.967935f, 0.507420f, 0.299654f,
                0.969319f, 0.517416f, 0.304268f,
                0.970704f, 0.527413f, 0.308881f,
                0.972088f, 0.537409f, 0.313495f,
                0.973472f, 0.547405f, 0.318108f,
                0.974856f, 0.557401f, 0.322722f,
                0.976240f, 0.567397f, 0.327336f,
                0.977624f, 0.577393f, 0.331949f,
                0.979008f, 0.587389f, 0.336563f,
                0.980392f, 0.597386f, 0.341176f,
                0.981776f, 0.607382f, 0.345790f,
                0.983160f, 0.617378f, 0.350404f,
                0.984544f, 0.627374f, 0.355017f,
                0.985928f, 0.637370f, 0.359631f,
                0.987313f, 0.647366f, 0.364245f,
                0.988697f, 0.657363f, 0.368858f,
                0.990081f, 0.667359f, 0.373472f,
                0.991465f, 0.677355f, 0.378085f,
                0.992234f, 0.686198f, 0.383622f,
                0.992388f, 0.693887f, 0.390081f,
                0.992541f, 0.701576f, 0.396540f,
                0.992695f, 0.709266f, 0.402999f,
                0.992849f, 0.716955f, 0.409458f,
                0.993003f, 0.724644f, 0.415917f,
                0.993156f, 0.732334f, 0.422376f,
                0.993310f, 0.740023f, 0.428835f,
                0.993464f, 0.747712f, 0.435294f,
                0.993618f, 0.755402f, 0.441753f,
                0.993772f, 0.763091f, 0.448212f,
                0.993925f, 0.770780f, 0.454671f,
                0.994079f, 0.778470f, 0.461130f,
                0.994233f, 0.786159f, 0.467589f,
                0.994387f, 0.793849f, 0.474048f,
                0.994541f, 0.801538f, 0.480507f,
                0.994694f, 0.809227f, 0.486967f,
                0.994848f, 0.816917f, 0.493426f,
                0.995002f, 0.824606f, 0.499885f,
                0.995156f, 0.832295f, 0.506344f,
                0.995309f, 0.839985f, 0.512803f,
                0.995463f, 0.847674f, 0.519262f,
                0.995617f, 0.855363f, 0.525721f,
                0.995771f, 0.863053f, 0.532180f,
                0.995925f, 0.870742f, 0.538639f,
                0.996078f, 0.878431f, 0.545098f,
                0.996232f, 0.883199f, 0.553095f,
                0.996386f, 0.887966f, 0.561092f,
                0.996540f, 0.892734f, 0.569089f,
                0.996694f, 0.897501f, 0.577086f,
                0.996847f, 0.902268f, 0.585083f,
                0.997001f, 0.907036f, 0.593080f,
                0.997155f, 0.911803f, 0.601077f,
                0.997309f, 0.916571f, 0.609073f,
                0.997463f, 0.921338f, 0.617070f,
                0.997616f, 0.926105f, 0.625067f,
                0.997770f, 0.930873f, 0.633064f,
                0.997924f, 0.935640f, 0.641061f,
                0.998078f, 0.940408f, 0.649058f,
                0.998231f, 0.945175f, 0.657055f,
                0.998385f, 0.949942f, 0.665052f,
                0.998539f, 0.954710f, 0.673049f,
                0.998693f, 0.959477f, 0.681046f,
                0.998847f, 0.964245f, 0.689043f,
                0.999000f, 0.969012f, 0.697040f,
                0.999154f, 0.973779f, 0.705037f,
                0.999308f, 0.978547f, 0.713033f,
                0.999462f, 0.983314f, 0.721030f,
                0.999616f, 0.988082f, 0.729027f,
                0.999769f, 0.992849f, 0.737024f,
                0.999923f, 0.997616f, 0.745021f,
                0.998078f, 0.999231f, 0.746021f,
                0.994233f, 0.997693f, 0.740023f,
                0.990388f, 0.996155f, 0.734025f,
                0.986544f, 0.994617f, 0.728028f,
                0.982699f, 0.993080f, 0.722030f,
                0.978854f, 0.991542f, 0.716032f,
                0.975010f, 0.990004f, 0.710035f,
                0.971165f, 0.988466f, 0.704037f,
                0.967320f, 0.986928f, 0.698039f,
                0.963476f, 0.985390f, 0.692042f,
                0.959631f, 0.983852f, 0.686044f,
                0.955786f, 0.982314f, 0.680046f,
                0.951942f, 0.980777f, 0.674048f,
                0.948097f, 0.979239f, 0.668051f,
                0.944252f, 0.977701f, 0.662053f,
                0.940408f, 0.976163f, 0.656055f,
                0.936563f, 0.974625f, 0.650058f,
                0.932718f, 0.973087f, 0.644060f,
                0.928874f, 0.971549f, 0.638062f,
                0.925029f, 0.970012f, 0.632065f,
                0.921184f, 0.968474f, 0.626067f,
                0.917339f, 0.966936f, 0.620069f,
                0.913495f, 0.965398f, 0.614072f,
                0.909650f, 0.963860f, 0.608074f,
                0.905805f, 0.962322f, 0.602076f,
                0.901961f, 0.960784f, 0.596078f,
                0.892887f, 0.957093f, 0.597924f,
                0.883814f, 0.953403f, 0.599769f,
                0.874740f, 0.949712f, 0.601615f,
                0.865667f, 0.946021f, 0.603460f,
                0.856594f, 0.942330f, 0.605306f,
                0.847520f, 0.938639f, 0.607151f,
                0.838447f, 0.934948f, 0.608997f,
                0.829373f, 0.931257f, 0.610842f,
                0.820300f, 0.927566f, 0.612687f,
                0.811226f, 0.923875f, 0.614533f,
                0.802153f, 0.920185f, 0.616378f,
                0.793080f, 0.916494f, 0.618224f,
                0.784006f, 0.912803f, 0.620069f,
                0.774933f, 0.909112f, 0.621915f,
                0.765859f, 0.905421f, 0.623760f,
                0.756786f, 0.901730f, 0.625606f,
                0.747712f, 0.898039f, 0.627451f,
                0.738639f, 0.894348f, 0.629296f,
                0.729566f, 0.890657f, 0.631142f,
                0.720492f, 0.886967f, 0.632987f,
                0.711419f, 0.883276f, 0.634833f,
                0.702345f, 0.879585f, 0.636678f,
                0.693272f, 0.875894f, 0.638524f,
                0.684198f, 0.872203f, 0.640369f,
                0.675125f, 0.868512f, 0.642215f,
                0.665283f, 0.864591f, 0.643214f,
                0.654671f, 0.860438f, 0.643368f,
                0.644060f, 0.856286f, 0.643522f,
                0.633449f, 0.852134f, 0.643676f,
                0.622837f, 0.847982f, 0.643829f,
                0.612226f, 0.843829f, 0.643983f,
                0.601615f, 0.839677f, 0.644137f,
                0.591003f, 0.835525f, 0.644291f,
                0.580392f, 0.831373f, 0.644444f,
                0.569781f, 0.827220f, 0.644598f,
                0.559170f, 0.823068f, 0.644752f,
                0.548558f, 0.818916f, 0.644906f,
                0.537947f, 0.814764f, 0.645060f,
                0.527336f, 0.810611f, 0.645213f,
                0.516724f, 0.806459f, 0.645367f,
                0.506113f, 0.802307f, 0.645521f,
                0.495502f, 0.798155f, 0.645675f,
                0.484890f, 0.794002f, 0.645829f,
                0.474279f, 0.789850f, 0.645982f,
                0.463668f, 0.785698f, 0.646136f,
                0.453057f, 0.781546f, 0.646290f,
                0.442445f, 0.777393f, 0.646444f,
                0.431834f, 0.773241f, 0.646597f,
                0.421223f, 0.769089f, 0.646751f,
                0.410611f, 0.764937f, 0.646905f,
                0.400000f, 0.760784f, 0.647059f,
                0.392003f, 0.751865f, 0.650750f,
                0.384006f, 0.742945f, 0.654441f,
                0.376009f, 0.734025f, 0.658131f,
                0.368012f, 0.725106f, 0.661822f,
                0.360015f, 0.716186f, 0.665513f,
                0.352018f, 0.707266f, 0.669204f,
                0.344022f, 0.698347f, 0.672895f,
                0.336025f, 0.689427f, 0.676586f,
                0.328028f, 0.680507f, 0.680277f,
                0.320031f, 0.671588f, 0.683968f,
                0.312034f, 0.662668f, 0.687659f,
                0.304037f, 0.653749f, 0.691349f,
                0.296040f, 0.644829f, 0.695040f,
                0.288043f, 0.635909f, 0.698731f,
                0.280046f, 0.626990f, 0.702422f,
                0.272049f, 0.618070f, 0.706113f,
                0.264052f, 0.609150f, 0.709804f,
                0.256055f, 0.600231f, 0.713495f,
                0.248058f, 0.591311f, 0.717186f,
                0.240062f, 0.582391f, 0.720877f,
                0.232065f, 0.573472f, 0.724567f,
                0.224068f, 0.564552f, 0.728258f,
                0.216071f, 0.555632f, 0.731949f,
                0.208074f, 0.546713f, 0.735640f,
                0.200077f, 0.537793f, 0.739331f,
                0.199462f, 0.528950f, 0.739100f,
                0.206228f, 0.520185f, 0.734948f,
                0.212995f, 0.511419f, 0.730796f,
                0.219762f, 0.502653f, 0.726644f,
                0.226528f, 0.493887f, 0.722491f,
                0.233295f, 0.485121f, 0.718339f,
                0.240062f, 0.476355f, 0.714187f,
                0.246828f, 0.467589f, 0.710035f,
                0.253595f, 0.458824f, 0.705882f,
                0.260361f, 0.450058f, 0.701730f,
                0.267128f, 0.441292f, 0.697578f,
                0.273895f, 0.432526f, 0.693426f,
                0.280661f, 0.423760f, 0.689273f,
                0.287428f, 0.414994f, 0.685121f,
                0.294195f, 0.406228f, 0.680969f,
                0.300961f, 0.397463f, 0.676817f,
                0.307728f, 0.388697f, 0.672664f,
                0.314494f, 0.379931f, 0.668512f,
                0.321261f, 0.371165f, 0.664360f,
                0.328028f, 0.362399f, 0.660208f,
                0.334794f, 0.353633f, 0.656055f,
                0.341561f, 0.344867f, 0.651903f,
                0.348328f, 0.336101f, 0.647751f,
                0.355094f, 0.327336f, 0.643599f,
                0.361861f, 0.318570f, 0.639446f,
                0.368627f, 0.309804f, 0.635294f};