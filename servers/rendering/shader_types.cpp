/*************************************************************************/
/*  shader_types.cpp                                                     */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2020 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2020 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "shader_types.h"

const Map<StringName, ShaderLanguage::FunctionInfo> &ShaderTypes::get_functions(RS::ShaderMode p_mode) {
	return shader_modes[p_mode].functions;
}

const Vector<StringName> &ShaderTypes::get_modes(RS::ShaderMode p_mode) {
	return shader_modes[p_mode].modes;
}

const Set<String> &ShaderTypes::get_types() {
	return shader_types;
}

ShaderTypes *ShaderTypes::singleton = nullptr;

static ShaderLanguage::BuiltInInfo constt(ShaderLanguage::DataType p_type) {
	return ShaderLanguage::BuiltInInfo(p_type, true);
}

ShaderTypes::ShaderTypes() {
	singleton = this;

	/*************** SPATIAL ***********************/

	shader_modes[RS::SHADER_SPATIAL].functions["global"].built_ins["TIME"] = constt(ShaderLanguage::TYPE_FLOAT);

	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["VERTEX"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["NORMAL"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["TANGENT"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["BINORMAL"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["POSITION"] = ShaderLanguage::TYPE_VEC4;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["UV"] = ShaderLanguage::TYPE_VEC2;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["UV2"] = ShaderLanguage::TYPE_VEC2;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["COLOR"] = ShaderLanguage::TYPE_VEC4;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["POINT_SIZE"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["INSTANCE_ID"] = constt(ShaderLanguage::TYPE_INT);
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["INSTANCE_CUSTOM"] = constt(ShaderLanguage::TYPE_VEC4);
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["ROUGHNESS"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].can_discard = false;

	//builtins
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["WORLD_MATRIX"] = ShaderLanguage::TYPE_MAT4;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["WORLD_NORMAL_MATRIX"] = ShaderLanguage::TYPE_MAT3;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["INV_CAMERA_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["CAMERA_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["PROJECTION_MATRIX"] = ShaderLanguage::TYPE_MAT4;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["INV_PROJECTION_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["MODELVIEW_MATRIX"] = ShaderLanguage::TYPE_MAT4;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["MODELVIEW_NORMAL_MATRIX"] = ShaderLanguage::TYPE_MAT3;
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["VIEWPORT_SIZE"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_SPATIAL].functions["vertex"].built_ins["OUTPUT_IS_SRGB"] = constt(ShaderLanguage::TYPE_BOOL);

	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["VERTEX"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["FRAGCOORD"] = constt(ShaderLanguage::TYPE_VEC4);
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["FRONT_FACING"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["NORMAL"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["TANGENT"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["BINORMAL"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["VIEW"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["NORMALMAP"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["NORMALMAP_DEPTH"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["UV"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["UV2"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["COLOR"] = constt(ShaderLanguage::TYPE_VEC4);
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["ALBEDO"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["ALPHA"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["METALLIC"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["SPECULAR"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["ROUGHNESS"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["RIM"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["RIM_TINT"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["CLEARCOAT"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["CLEARCOAT_GLOSS"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["ANISOTROPY"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["ANISOTROPY_FLOW"] = ShaderLanguage::TYPE_VEC2;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["SSS_STRENGTH"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["SSS_TRANSMITTANCE_COLOR"] = ShaderLanguage::TYPE_VEC4;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["SSS_TRANSMITTANCE_DEPTH"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["SSS_TRANSMITTANCE_CURVE"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["SSS_TRANSMITTANCE_BOOST"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["BACKLIGHT"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["AO"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["AO_LIGHT_AFFECT"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["EMISSION"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["SCREEN_TEXTURE"] = ShaderLanguage::TYPE_SAMPLER2D;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["NORMAL_ROUGHNESS_TEXTURE"] = ShaderLanguage::TYPE_SAMPLER2D;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["DEPTH_TEXTURE"] = ShaderLanguage::TYPE_SAMPLER2D;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["DEPTH"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["SCREEN_UV"] = ShaderLanguage::TYPE_VEC2;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["POINT_COORD"] = constt(ShaderLanguage::TYPE_VEC2);

	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["OUTPUT_IS_SRGB"] = constt(ShaderLanguage::TYPE_BOOL);

	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["WORLD_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["WORLD_NORMAL_MATRIX"] = constt(ShaderLanguage::TYPE_MAT3);
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["INV_CAMERA_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["CAMERA_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["PROJECTION_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["INV_PROJECTION_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["VIEWPORT_SIZE"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["FOG"] = ShaderLanguage::TYPE_VEC4; // TODO consider adding to light shader
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["RADIANCE"] = ShaderLanguage::TYPE_VEC4;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].built_ins["IRRADIANCE"] = ShaderLanguage::TYPE_VEC4;
	shader_modes[RS::SHADER_SPATIAL].functions["fragment"].can_discard = true;

	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["WORLD_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["INV_CAMERA_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["CAMERA_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["PROJECTION_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["INV_PROJECTION_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["VIEWPORT_SIZE"] = constt(ShaderLanguage::TYPE_VEC2);

	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["FRAGCOORD"] = constt(ShaderLanguage::TYPE_VEC4);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["NORMAL"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["UV"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["UV2"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["VIEW"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["LIGHT"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["LIGHT_COLOR"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["ATTENUATION"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["SHADOW_ATTENUATION"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["ALBEDO"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["BACKLIGHT"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["METALLIC"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["ROUGHNESS"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["DIFFUSE_LIGHT"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["SPECULAR_LIGHT"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["OUTPUT_IS_SRGB"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_SPATIAL].functions["light"].built_ins["ALPHA"] = ShaderLanguage::TYPE_FLOAT;

	shader_modes[RS::SHADER_SPATIAL].functions["light"].can_discard = true;

	//order used puts first enum mode (default) first
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("blend_mix");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("blend_add");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("blend_sub");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("blend_mul");

	shader_modes[RS::SHADER_SPATIAL].modes.push_back("depth_draw_opaque");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("depth_draw_always");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("depth_draw_never");

	shader_modes[RS::SHADER_SPATIAL].modes.push_back("depth_prepass_alpha");

	shader_modes[RS::SHADER_SPATIAL].modes.push_back("depth_test_disabled");

	shader_modes[RS::SHADER_SPATIAL].modes.push_back("sss_mode_skin");

	shader_modes[RS::SHADER_SPATIAL].modes.push_back("cull_back");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("cull_front");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("cull_disabled");

	shader_modes[RS::SHADER_SPATIAL].modes.push_back("unshaded");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("wireframe");

	shader_modes[RS::SHADER_SPATIAL].modes.push_back("diffuse_lambert");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("diffuse_lambert_wrap");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("diffuse_oren_nayar");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("diffuse_burley");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("diffuse_toon");

	shader_modes[RS::SHADER_SPATIAL].modes.push_back("specular_schlick_ggx");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("specular_blinn");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("specular_phong");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("specular_toon");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("specular_disabled");

	shader_modes[RS::SHADER_SPATIAL].modes.push_back("skip_vertex_transform");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("world_vertex_coords");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("ensure_correct_normals");

	shader_modes[RS::SHADER_SPATIAL].modes.push_back("shadows_disabled");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("ambient_light_disabled");
	shader_modes[RS::SHADER_SPATIAL].modes.push_back("shadow_to_opacity");

	shader_modes[RS::SHADER_SPATIAL].modes.push_back("vertex_lighting");

	/************ CANVAS ITEM **************************/

	shader_modes[RS::SHADER_CANVAS_ITEM].functions["global"].built_ins["TIME"] = constt(ShaderLanguage::TYPE_FLOAT);

	shader_modes[RS::SHADER_CANVAS_ITEM].functions["vertex"].built_ins["VERTEX"] = ShaderLanguage::TYPE_VEC2;
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["vertex"].built_ins["UV"] = ShaderLanguage::TYPE_VEC2;
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["vertex"].built_ins["COLOR"] = ShaderLanguage::TYPE_VEC4;
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["vertex"].built_ins["POINT_SIZE"] = ShaderLanguage::TYPE_FLOAT;

	shader_modes[RS::SHADER_CANVAS_ITEM].functions["vertex"].built_ins["WORLD_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["vertex"].built_ins["CANVAS_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["vertex"].built_ins["SCREEN_MATRIX"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["vertex"].built_ins["INSTANCE_CUSTOM"] = constt(ShaderLanguage::TYPE_VEC4);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["vertex"].built_ins["AT_LIGHT_PASS"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["vertex"].built_ins["TEXTURE_PIXEL_SIZE"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["vertex"].can_discard = false;

	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["VERTEX"] = ShaderLanguage::TYPE_VEC2;
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["SHADOW_VERTEX"] = ShaderLanguage::TYPE_VEC2;
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["LIGHT_VERTEX"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["FRAGCOORD"] = constt(ShaderLanguage::TYPE_VEC4);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["NORMAL"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["NORMALMAP"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["NORMALMAP_DEPTH"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["UV"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["COLOR"] = ShaderLanguage::TYPE_VEC4;
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["TEXTURE"] = constt(ShaderLanguage::TYPE_SAMPLER2D);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["TEXTURE_PIXEL_SIZE"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["NORMAL_TEXTURE"] = constt(ShaderLanguage::TYPE_SAMPLER2D);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["SPECULAR_SHININESS_TEXTURE"] = constt(ShaderLanguage::TYPE_SAMPLER2D);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["SPECULAR_SHININESS"] = constt(ShaderLanguage::TYPE_VEC4);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["SCREEN_UV"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["SCREEN_PIXEL_SIZE"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["POINT_COORD"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["AT_LIGHT_PASS"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].built_ins["SCREEN_TEXTURE"] = constt(ShaderLanguage::TYPE_SAMPLER2D);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["fragment"].can_discard = true;

	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].built_ins["FRAGCOORD"] = constt(ShaderLanguage::TYPE_VEC4);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].built_ins["NORMAL"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].built_ins["COLOR"] = constt(ShaderLanguage::TYPE_VEC4);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].built_ins["UV"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].built_ins["SPECULAR_SHININESS"] = constt(ShaderLanguage::TYPE_VEC4);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].built_ins["LIGHT_COLOR"] = constt(ShaderLanguage::TYPE_VEC4);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].built_ins["LIGHT_POSITION"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].built_ins["LIGHT_VERTEX"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].built_ins["LIGHT"] = ShaderLanguage::TYPE_VEC4;
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].built_ins["SHADOW_MODULATE"] = ShaderLanguage::TYPE_VEC4;
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].built_ins["SCREEN_UV"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].built_ins["TEXTURE"] = constt(ShaderLanguage::TYPE_SAMPLER2D);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].built_ins["TEXTURE_PIXEL_SIZE"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].built_ins["POINT_COORD"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_CANVAS_ITEM].functions["light"].can_discard = true;

	shader_modes[RS::SHADER_CANVAS_ITEM].modes.push_back("skip_vertex_transform");

	shader_modes[RS::SHADER_CANVAS_ITEM].modes.push_back("blend_mix");
	shader_modes[RS::SHADER_CANVAS_ITEM].modes.push_back("blend_add");
	shader_modes[RS::SHADER_CANVAS_ITEM].modes.push_back("blend_sub");
	shader_modes[RS::SHADER_CANVAS_ITEM].modes.push_back("blend_mul");
	shader_modes[RS::SHADER_CANVAS_ITEM].modes.push_back("blend_premul_alpha");
	shader_modes[RS::SHADER_CANVAS_ITEM].modes.push_back("blend_disabled");

	shader_modes[RS::SHADER_CANVAS_ITEM].modes.push_back("unshaded");
	shader_modes[RS::SHADER_CANVAS_ITEM].modes.push_back("light_only");

	/************ PARTICLES **************************/

	shader_modes[RS::SHADER_PARTICLES].functions["global"].built_ins["TIME"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["COLOR"] = ShaderLanguage::TYPE_VEC4;
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["VELOCITY"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["MASS"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["ACTIVE"] = ShaderLanguage::TYPE_BOOL;
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["RESTART"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["CUSTOM"] = ShaderLanguage::TYPE_VEC4;
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["TRANSFORM"] = ShaderLanguage::TYPE_MAT4;
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["LIFETIME"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["DELTA"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["NUMBER"] = constt(ShaderLanguage::TYPE_UINT);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["INDEX"] = constt(ShaderLanguage::TYPE_INT);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["EMISSION_TRANSFORM"] = constt(ShaderLanguage::TYPE_MAT4);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["RANDOM_SEED"] = constt(ShaderLanguage::TYPE_UINT);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["FLAG_EMIT_POSITION"] = constt(ShaderLanguage::TYPE_UINT);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["FLAG_EMIT_ROT_SCALE"] = constt(ShaderLanguage::TYPE_UINT);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["FLAG_EMIT_VELOCITY"] = constt(ShaderLanguage::TYPE_UINT);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["FLAG_EMIT_COLOR"] = constt(ShaderLanguage::TYPE_UINT);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["FLAG_EMIT_CUSTOM"] = constt(ShaderLanguage::TYPE_UINT);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["RESTART_POSITION"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["RESTART_ROT_SCALE"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["RESTART_VELOCITY"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["RESTART_COLOR"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["RESTART_CUSTOM"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["COLLIDED"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["COLLISION_NORMAL"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["COLLISION_DEPTH"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].built_ins["ATTRACTOR_FORCE"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_PARTICLES].functions["compute"].can_discard = false;

	{
		ShaderLanguage::StageFunctionInfo emit_vertex_func;
		emit_vertex_func.arguments.push_back(ShaderLanguage::StageFunctionInfo::Argument("xform", ShaderLanguage::TYPE_MAT4));
		emit_vertex_func.arguments.push_back(ShaderLanguage::StageFunctionInfo::Argument("velocity", ShaderLanguage::TYPE_VEC3));
		emit_vertex_func.arguments.push_back(ShaderLanguage::StageFunctionInfo::Argument("color", ShaderLanguage::TYPE_VEC4));
		emit_vertex_func.arguments.push_back(ShaderLanguage::StageFunctionInfo::Argument("custom", ShaderLanguage::TYPE_VEC4));
		emit_vertex_func.arguments.push_back(ShaderLanguage::StageFunctionInfo::Argument("flags", ShaderLanguage::TYPE_UINT));
		emit_vertex_func.return_type = ShaderLanguage::TYPE_BOOL; //whether it could emit
		shader_modes[RS::SHADER_PARTICLES].functions["compute"].stage_functions["emit_particle"] = emit_vertex_func;
	}

	shader_modes[RS::SHADER_PARTICLES].modes.push_back("collision_use_scale");
	shader_modes[RS::SHADER_PARTICLES].modes.push_back("disable_force");
	shader_modes[RS::SHADER_PARTICLES].modes.push_back("disable_velocity");
	shader_modes[RS::SHADER_PARTICLES].modes.push_back("keep_data");

	/************ SKY **************************/

	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["TIME"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["POSITION"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["RADIANCE"] = constt(ShaderLanguage::TYPE_SAMPLERCUBE);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["AT_HALF_RES_PASS"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["AT_QUARTER_RES_PASS"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["AT_CUBEMAP_PASS"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT0_ENABLED"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT0_DIRECTION"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT0_ENERGY"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT0_COLOR"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT0_SIZE"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT1_ENABLED"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT1_DIRECTION"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT1_ENERGY"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT1_COLOR"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT1_SIZE"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT2_ENABLED"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT2_DIRECTION"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT2_ENERGY"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT2_COLOR"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT2_SIZE"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT3_ENABLED"] = constt(ShaderLanguage::TYPE_BOOL);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT3_DIRECTION"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT3_ENERGY"] = constt(ShaderLanguage::TYPE_FLOAT);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT3_COLOR"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SKY].functions["global"].built_ins["LIGHT3_SIZE"] = constt(ShaderLanguage::TYPE_FLOAT);

	shader_modes[RS::SHADER_SKY].functions["fragment"].built_ins["COLOR"] = ShaderLanguage::TYPE_VEC3;
	shader_modes[RS::SHADER_SKY].functions["fragment"].built_ins["ALPHA"] = ShaderLanguage::TYPE_FLOAT;
	shader_modes[RS::SHADER_SKY].functions["fragment"].built_ins["EYEDIR"] = constt(ShaderLanguage::TYPE_VEC3);
	shader_modes[RS::SHADER_SKY].functions["fragment"].built_ins["SCREEN_UV"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_SKY].functions["fragment"].built_ins["SKY_COORDS"] = constt(ShaderLanguage::TYPE_VEC2);
	shader_modes[RS::SHADER_SKY].functions["fragment"].built_ins["HALF_RES_COLOR"] = constt(ShaderLanguage::TYPE_VEC4);
	shader_modes[RS::SHADER_SKY].functions["fragment"].built_ins["QUARTER_RES_COLOR"] = constt(ShaderLanguage::TYPE_VEC4);
	shader_modes[RS::SHADER_SKY].functions["fragment"].built_ins["FOG"] = ShaderLanguage::TYPE_VEC4;

	shader_modes[RS::SHADER_SKY].modes.push_back("use_half_res_pass");
	shader_modes[RS::SHADER_SKY].modes.push_back("use_quarter_res_pass");
	shader_modes[RS::SHADER_SKY].modes.push_back("disable_fog");

	shader_types.insert("spatial");
	shader_types.insert("canvas_item");
	shader_types.insert("particles");
	shader_types.insert("sky");
}
